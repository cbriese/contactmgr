#include <QApplication>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include <QFrame>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QHeaderView>
#include <QLabel>
#include <cstdlib>
#include "mainwindow.h"

bool connectToDatabase() {
	QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
	// NEED to replace with environment variables
	if (std::getenv("DB_HOSTNAME") != "") {
		db.setHostName(std::getenv("DB_HOSTNAME"));
	} else {
		return false;
	}

	if (std::getenv("DB_NAME") != "") {
		db.setDatabaseName(std::getenv("DB_NAME"));
	} else {
		return false;
	}

	if (std::getenv("DB_USERNAME") != "") {
		db.setUserName(std::getenv("DB_USERNAME"));
	} else {
		return false;
	}

	if (std::getenv("DB_PASSWORD") != "") {
		db.setPassword(std::getenv("DB_PASSWORD"));
	} else {
		return false;
	}

	if (!db.open()) {
		qDebug() << "Database connection failed:" << db.lastError().text();
		return false;
	} else {
		qDebug() << "Database connected successfully.";
		return true;
	}
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	if (!connectToDatabase()) {
		return -1;
	}

	// Create a QSqlQueryModel to hold the data
	QSqlQueryModel *model = new QSqlQueryModel();
	model->setQuery("SELECT id, first_name, last_name FROM public.contacts ORDER BY id ASC");

	// Check for query errors
	if (model->lastError().isValid()) {
		qDebug() << "Query failed:" << model->lastError().text();
		return -1;
	}

	// Set human-readable headers (optional)
	model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
	model->setHeaderData(1, Qt::Horizontal, QObject::tr("First Name"));
	model->setHeaderData(2, Qt::Horizontal, QObject::tr("Last Name"));

	// Create a QTableView and set the model
	QTableView *view = new QTableView();
	view->setModel(model);
	view->horizontalHeader()->setStretchLastSection(true);
	view->resizeColumnsToContents();

	// Create the main window
	MainWindow w;

	// Create a central widget
	QWidget *centralWidget = new QWidget();

	// Create a frame to old the data entry widgets
	QFrame *dataEntryFrame = new QFrame();

	// Create a layout for the data entry widgets
	QGridLayout *dataEntryLayout = new QGridLayout(dataEntryFrame);

	// Create labels for data entry
	QLabel *firstLabel = new QLabel(QObject::tr("First Name"));
	QLabel *lastLabel = new QLabel(QObject::tr("Last Name"));

	// Add labels to data entry layout
	dataEntryLayout->addWidget(firstLabel, 0, 0);
	dataEntryLayout->addWidget(lastLabel, 1, 0);

	// Hide the vertical header of the table
	view->verticalHeader()->hide();

	// Create a layout for the central widget
	QVBoxLayout *layout = new QVBoxLayout(centralWidget);

	// Add data entry and display widgets to the central widget layout
	layout->addWidget(dataEntryFrame);
	layout->addWidget(view);

	// Set the central widget for the main window
	w.setCentralWidget(centralWidget);

	// Set title
	w.setWindowTitle("Qt Demo Application");

	// Show main window
	w.show();

	// Run it
	return a.exec();
}


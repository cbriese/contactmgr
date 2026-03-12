#include <QApplication>
#include <QTableView>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDebug>
#include <QSqlError>
#include <QVBoxLayout>
#include <QWidget>
#include <QHeaderView>

bool connectToDatabase() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QPSQL");
    db.setHostName("localhost"); // Or your server's IP
    db.setDatabaseName("postgres");
    db.setUserName("postgres");
    db.setPassword("underwear");

    if (!db.open()) {
        qDebug() << "Database connection failed:" << db.lastError().text();
        return false;
    } else {
        qDebug() << "Database connected successfully.";
        return true;
    }
}

int main(int argc, char *argv[]) {
    qDebug() << "Starting the program";
    QApplication a(argc, argv);

    if (!connectToDatabase()) {
        return -1;
    }

    // Create a QSqlQueryModel to hold the data
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT name, population FROM public.cities ORDER BY name ASC"); // Your SQL query

    // Check for query errors
    if (model->lastError().isValid()) {
        qDebug() << "Query failed:" << model->lastError().text();
        return -1;
    }

    // Set human-readable headers (optional)
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("City Name"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Population"));

    // Create a QTableView and set the model
    QTableView *view = new QTableView();
    view->setModel(model);
    view->horizontalHeader()->setStretchLastSection(true);
    view->resizeColumnsToContents();

    // Create a main window/widget to display the table
    QWidget window;
    QVBoxLayout *layout = new QVBoxLayout(&window);
    layout->addWidget(view);
    window.setLayout(layout);
    window.setWindowTitle("PostgreSQL Data in Qt Table");
    window.show();

    return a.exec();
}


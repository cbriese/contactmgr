#include <QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QHeaderView>

int main(int argc, char *argv[]) {
    // 1. Initialize the QApplication
    QApplication app(argc, argv);

    // 2. Create the main window or widget
    QWidget window;
    window.setWindowTitle("Qt 6 QTableWidget Example");
    window.resize(400, 300);

    // 3. Create the QTableWidget instance
    QTableWidget *tableWidget = new QTableWidget(&window);
    tableWidget->setColumnCount(2); // Set two columns
    tableWidget->setRowCount(2);    // Set two rows
    tableWidget->setGeometry(10, 10, 380, 280); // Set position and size

    // 4. Set headers for the columns
    QStringList headers;
    headers << "Column 1" << "Column 2";
    tableWidget->setHorizontalHeaderLabels(headers);

    // 5. Populate the table with data
    // Row 0, Column 0
    QTableWidgetItem *item00 = new QTableWidgetItem("Data A");
    tableWidget->setItem(0, 0, item00);
    // Row 0, Column 1
    QTableWidgetItem *item01 = new QTableWidgetItem("Data B");
    tableWidget->setItem(0, 1, item01);
    // Row 1, Column 0
    QTableWidgetItem *item10 = new QTableWidgetItem("Data C");
    tableWidget->setItem(1, 0, item10);
    // Row 1, Column 1
    QTableWidgetItem *item11 = new QTableWidgetItem("Data D");
    tableWidget->setItem(1, 1, item11);

    // Optional: Resize columns to fit content
    tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    // 6. Show the window and run the application
    window.show();
    return app.exec();
}


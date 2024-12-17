#include <QApplication>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QVBoxLayout>
#include <QWidget>
#include <QLabel>
#include "Database.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Hardcode the CSV file name
    QString csvFileName = "teams.csv"; // Update with the name of your CSV file
    std::string dataFolder = "D:/Projects/C++ Projects/cpp_projects/cse225Projects3.0/Paris_Olympics_Analysis/Paris_Olympics_Analysis/data"; // Folder where the CSV files are stored
    std::string fullFilePath = dataFolder + csvFileName.toStdString();

    // Create a Database object and load the CSV file
    Database db;
    db.loadDatabase(dataFolder);

    // Get the LinkedList for the specified CSV file
    LinkedList *table = db.getTable(csvFileName.toStdString());
    if (!table) {
        qCritical() << "Table not found for file:" << csvFileName;
        return -1;
    }

    // Create the UI
    QWidget mainWindow;
    mainWindow.setWindowTitle("CSV Viewer");

    QVBoxLayout *layout = new QVBoxLayout(&mainWindow);

    // Add a heading
    QLabel *heading = new QLabel(QString("Viewing Table: %1").arg(csvFileName));
    heading->setStyleSheet("font-size: 16px; font-weight: bold; margin-bottom: 10px;");
    layout->addWidget(heading);

    // Create a QTableWidget to display the data
    QTableWidget *tableWidget = new QTableWidget(&mainWindow);

    // Set up the columns
    const auto &columns = table->columns;
    tableWidget->setColumnCount(static_cast<int>(columns.size()));
    QStringList headers;
    for (const auto &column : columns) {
        headers << QString::fromStdString(column);
    }
    tableWidget->setHorizontalHeaderLabels(headers);

    // Populate the rows
    Node *current = table->getHead();
    int row = 0;
    while (current) {
        tableWidget->insertRow(row);
        for (size_t col = 0; col < current->data.size(); ++col) {
            tableWidget->setItem(row, static_cast<int>(col),
                                 new QTableWidgetItem(QString::fromStdString(current->data[col])));
        }
        current = current->next;
        ++row;
    }

    // Adjust table properties
    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    tableWidget->resizeColumnsToContents();
    tableWidget->resizeRowsToContents();

    layout->addWidget(tableWidget);

    mainWindow.resize(800, 600);
    mainWindow.show();

    return app.exec();
}

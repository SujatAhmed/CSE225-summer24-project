#include <QApplication>
#include <QInputDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QWidget>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <iostream>
#include "Database.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Hardcoded CSV file name
    QString csvFileName = "athletes.csv"; // Update with the name of your CSV file
    std::string dataFolder = "D:/Projects/C++ Projects/cpp_projects/cse225Projects3.0/Paris_Olympics_Analysis/Paris_Olympics_Analysis/data";    // Folder where the CSV files are stored
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

    // Display a search dialog
    bool ok;
    QString searchKey = QInputDialog::getText(nullptr, "Search", "Enter code to search:", QLineEdit::Normal, QString(), &ok);

    if (ok && !searchKey.isEmpty()) {
        int columnIndex = 0; // Default to the first column
        Node *result = db.search(csvFileName.toStdString(), searchKey.toStdString(), columnIndex);

        if (result) {
            // Display the found data
            QWidget resultWindow;
            resultWindow.setWindowTitle("Search Result");

            QVBoxLayout *layout = new QVBoxLayout(&resultWindow);
            QLabel *resultLabel = new QLabel("Search Result Found:", &resultWindow);
            layout->addWidget(resultLabel);

            QTableWidget *tableWidget = new QTableWidget(&resultWindow);
            tableWidget->setColumnCount(table->columns.size());
            QStringList headers;
            for (const auto &column : table->columns) {
                headers << QString::fromStdString(column);
            }
            tableWidget->setHorizontalHeaderLabels(headers);

            int row = 0;
            tableWidget->insertRow(row);
            for (size_t col = 0; col < result->data.size(); ++col) {
                tableWidget->setItem(row, static_cast<int>(col), new QTableWidgetItem(QString::fromStdString(result->data[col])));
            }

            layout->addWidget(tableWidget);
            resultWindow.resize(600, 400);
            resultWindow.show();

            return app.exec(); // Show search result and run the app loop
        } else {
            QLabel errorLabel("Code not found in the table.", nullptr);
            errorLabel.show();
            return app.exec(); // Show the error message and run the app loop
        }
    } else {
        QLabel infoLabel("Search canceled or empty input.", nullptr);
        infoLabel.show();
        return app.exec(); // Show the info message and run the app loop
    }
}

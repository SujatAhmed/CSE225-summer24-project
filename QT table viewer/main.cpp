#include <QApplication>
#include "TableViewer.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Hardcode the CSV file name
    QString csvFileName = "teams.csv"; // Update with the name of your CSV file
    std::string dataFolder = "D:/Projects/C++ Projects/cpp_projects/cse225Projects3.0/Paris_Olympics_Analysis/Paris_Olympics_Analysis/data"; // Folder where the CSV files are stored

    TableViewer viewer(csvFileName, dataFolder);
    viewer.show();

    return app.exec();
}

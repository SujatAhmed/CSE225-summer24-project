#include <QApplication>
#include "searchInCSV.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    // Hardcoded CSV file name and data folder path
    QString csvFileName = "athletes.csv"; // Update with the name of your CSV file
    std::string dataFolder = "D:/Projects/C++ Projects/cpp_projects/cse225Projects3.0/Paris_Olympics_Analysis/Paris_Olympics_Analysis/data/";

    // Call the searchInCSV function
    searchInCSV(csvFileName, dataFolder);

    return 0;
}

#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
    // Create the application object
    QApplication app(argc, argv);

    // Create and display the main window
    MainWindow mainWindow;
    mainWindow.show();

    // Start the event loop
    return app.exec();
}

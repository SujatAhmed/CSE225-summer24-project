
#include <QApplication>
#include <QDir>
#include <QLabel>
#include <QPixmap>
#include <QPushButton>
#include <QResizeEvent>
#include <QVBoxLayout>
#include <QWidget>
#include "ParisOlympicsAnalysis.h"


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  ParisOlympicsAnalysis viewer;
  viewer.show();
  return app.exec();
}


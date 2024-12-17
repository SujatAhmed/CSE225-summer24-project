
#include <QApplication>
#include "ParisOlympicsAnalysis.h"


int main(int argc, char *argv[]) {
  QApplication app(argc, argv);

  ParisOlympicsAnalysis viewer;
  viewer.show();
  return app.exec();
}


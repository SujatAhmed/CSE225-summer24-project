

#include "Database.h"
#include "Graphs.h"
#include "MenuHandler.h"
#include "QApplication"
#include "QWidget"
#include <qwidget.h>
#include <string>
#include <vector>

using namespace std;
int main(int argc, char *argv[]) {
  std::string dataFolder = "/home/sujat/projects/CSE225-summer24-project/data1";
  QString csvFileName = "athletes.csv"; // Update with the name of your CSV file
  //
  //
  Database *db = new Database();
  db->loadDatabase(dataFolder);
  cout << "works" << endl;

  MenuHandler menu(db, dataFolder);
  menu.start();


}

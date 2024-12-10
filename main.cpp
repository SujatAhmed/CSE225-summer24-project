#include "Database.h"
#include "Node.cpp"
#include <string>
using namespace std;

int main() {

  Database d;
  string dir = "/home/sujat/projects/CSE225-summer24-project/test-csv-dir";
  d.loadDatabase(dir);

}

#include "Database.h"
#include "Node.cpp"
#include <string>
using namespace std;

int main() {

  Database d;
  string f1 = "/home/sujat/projects/CSE225-summer24-project/test-csv-dir/SampleCSVFile_2kb.csv";
  string dir = "/home/sujat/projects/CSE225-summer24-project/test-csv-dir";
  d.loadDatabase(dir);
  d.getTable("SampleCSVFile_2kb.csv")->display();

  
  
  


	
}

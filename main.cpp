#include "Database.h"
#include "LinkedList.h"
#include "Node.cpp"
#include "Utils.h"
#include <iostream>
#include <string>
using namespace std;

int main() {

  Database d;
  string filename =
      "/home/sujat/projects/CSE225-summer24-project/data/coaches.csv";

  d.loadData(filename);
	LinkedList* l = d.getTable(filename);
	//l->display();
	l->displayColumns();
	cout << l->getHead()<<endl;
	cout << l->getSize()<<endl;
	
}

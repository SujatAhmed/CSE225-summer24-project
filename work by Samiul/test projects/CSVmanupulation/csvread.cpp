#include <iostream>
#include <fstream>
using namespace std;

void create()
{
    // file pointer
    fstream fout;
    // opens an existing csv file or creates a new file.
    fout.open("athletes.csv", ios::out);
    cout << "Enter the details of 5 students:"
         << " roll name maths phy chem bio"<< endl;
    int i, roll, phy, chem, math, bio;
    string name;

    // Read the input
    for (i = 0; i < 2; i++) {
        cin >> roll
            >> name
            >> math
            >> phy
            >> chem
            >> bio;
        // Insert the data to file
        fout << roll << ", "
             << name << ", "
             << math << ", "
             << phy << ", "
             << chem << ", "
             << bio
             << "\n";
    }
}
int main (){
create();
return 0;
}

//
// Created by sujat on 12/7/24.
//


#ifndef DATABASE_H
#define DATABASE_H

#include <unordered_map>
#include <string>
#include "LinkedList.h"

using namespace std;

class Database {
private:
    unordered_map<string, LinkedList> tables; // Maps filenames to linked lists

public:
    Database();

    void loadData(const string& filename); // Loads data from a CSV file into a linked list
    void insert(const string& tableName, const vector<string>& rowData);
    void remove(const string& tableName, int index);
    Node* search(const string& tableName, const string& key, int columnIndex);
    void displayTable(const string& tableName);
    void displayAllTables();

    LinkedList* getTable(const string& tableName);
};

#endif // DATABASE_H

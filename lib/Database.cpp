//
// Created by sujat on 12/7/24.
#include "Database.h"
#include "Utils.h" // For split and parseCSV functions
#include <iostream>
#include <stdexcept>

using namespace std;

// Constructor
Database::Database() {}

// Load data from a CSV file into a linked list
void Database::loadData(const string& filename) {

    /*if (data.empty()) {
        throw runtime_error("CSV file is empty or could not be parsed.");
    }*/
    LinkedList list;

    list.columns= generateHeaders(filename);
    parseCSV(filename, list);
    tables[filename] = list;
}

// Insert a new row into a specific table
void Database::insert(const string& tableName, const vector<string>& rowData) {
    if (tables.find(tableName) == tables.end()) {
        throw invalid_argument("Table " + tableName + " does not exist.");
    }

    tables[tableName].insert(rowData);
    cout << "Row inserted into " << tableName << " successfully." << endl;
}

// Remove a row from a specific table at a given index
void Database::remove(const string& tableName, int index) {
    if (tables.find(tableName) == tables.end()) {
        throw invalid_argument("Table " + tableName + " does not exist.");
    }

    tables[tableName].remove(index);
    cout << "Row at index " << index << " removed from " << tableName << " successfully." << endl;
}

// Search for a key in a specific column of a table
Node* Database::search(const string& tableName, const string& key, int& columnIndex) {
    if (tables.find(tableName) == tables.end()) {
        throw invalid_argument("Table " + tableName + " does not exist.");
    }

    return tables[tableName].search(key, columnIndex);
}

// Display all rows in a specific table
void Database::displayTable(const string& tableName) {
    if (tables.find(tableName) == tables.end()) {
        throw invalid_argument("Table " + tableName + " does not exist.");
    }

    tables[tableName].display();
}

// Display all tables in the database
void Database::displayAllTables() {
    for (const auto& pair : tables) {
        cout << "Table: " << pair.first << endl;
        pair.second.display();
        cout << endl;
    }
}

// Get a pointer to a table (linked list) by its name
LinkedList* Database::getTable(const string& tableName) {
    if (tables.find(tableName) == tables.end()) {
        return nullptr;
    }

    return &tables[tableName];
}


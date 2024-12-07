//
// Created by sujat on 12/7/24.
//

#ifndef LINKEDLIST_H
#define LINKEDLIST_H



#include "Node.h"
#include <vector>
#include <string>

using namespace std;

class LinkedList {
private:
    Node* head;
    Node* tail;
    int size;
    vector<string> columns;

public:
    LinkedList();
    ~LinkedList();

    void insert(const vector<string>& rowData);
    void remove(int index); // Removes node at specified index
    Node* search(const string& key, string& column); // Searches for a key in a specific column
    void display() const; // Prints all nodes

    int getSize() const;
    Node* getHead() const;
};


#endif //LINKEDLIST_H
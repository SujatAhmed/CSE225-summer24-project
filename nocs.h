#ifndef NOCS_H
#define NOCS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Define the structure for a linked list node
struct Nocs
{
    string code;         // Column: code
    string country;      // Column: country
    string country_long; // Column: country_long
    string tag;          // Column: tag
    string note;         // Column: note
    Nocs* next;

    // Constructor to initialize the node with data
    Nocs(const string& c, const string& cn, const string& cl, const string& t, const string& n)
        : code(c), country(cn), country_long(cl), tag(t), note(n), next(nullptr) {}
};

// LinkedList class declaration
class NocList
{
private:
    Nocs* head;
    Nocs* tail;

public:
    NocList();  // Constructor
    ~NocList(); // Destructor

    void addNode(const string& code, const string& country, const string& country_long, const string& tag, const string& note);
    void printList() const;
    void loadFromCSV(const string& filePath);
    void appendToCSVAndList(const string& filePath, const string& code, const string& country, const string& country_long, const string& tag, const string& note);
    void deleteFromCSVAndList(const string& filePath, const string& code);
};

#endif // NOCS_H

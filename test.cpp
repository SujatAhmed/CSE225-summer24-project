#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

// Define the structure for a linked list node
struct Node {
    string code;         // Column: code
    string country;      // Column: country
    string country_long; // Column: country_long
    string tag;          // Column: tag
    string note;         // Column: note
    Node* next;

    // Constructor to initialize the node with data
    Node(const string& c, const string& cn, const string& cl, const string& t, const string& n)
        : code(c), country(cn), country_long(cl), tag(t), note(n), next(nullptr) {}
};

// Function to add a new node to the linked list
Node* addNode(Node* tail, const string& code, const string& country,
              const string& country_long, const string& tag, const string& note) {
    Node* newNode = new Node(code, country, country_long, tag, note);
    if (tail) {
        tail->next = newNode;
    }
    return newNode;
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* current = head;
    while (current) {
        cout << "Code: " << current->code << ", "
             << "Country: " << current->country << ", "
             << "Country Long: " << current->country_long << ", "
             << "Tag: " << current->tag << ", "
             << "Note: " << current->note << endl;
        current = current->next;
    }
}

// Main function
int main() {
    ifstream file("/home/sujat/projects/CSE225-summer24-project/data/nocs.csv"); // Path to the CSV file
    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        return 1;
    }

    string line;
    Node* head = nullptr; // Head of the linked list
    Node* tail = nullptr; // Tail to keep track of the last node

    // Skip the header line
    //getline(file, line);

    // Read each row of the CSV
    while (getline(file, line)) {
        stringstream ss(line);
        string code, country, country_long, tag, note;

        // Parse the CSV line
        getline(ss, code, ',');
        getline(ss, country, ',');
        getline(ss, country_long, ',');
        getline(ss, tag, ',');
        getline(ss, note, ',');

        // Add node to the linked list
        if (head == nullptr) {
            head = new Node(code, country, country_long, tag, note);
            tail = head;
        } else {
            tail = addNode(tail, code, country, country_long, tag, note);
        }
    }

    file.close();

    // Print the linked list
    printLinkedList(head);

    // Cleanup: Free memory
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}



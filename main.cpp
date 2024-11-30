#include "nocs.h"

int main()
{
    NocList nocsList;

    // Load data from the CSV file
    string filePath = "data/nocs.csv";
    nocsList.loadFromCSV(filePath);

    // Print the linked list
    //nocsList.printList();

    // Append a new row to the CSV and linked list
    //cout << "\nAdding a new entry to the CSV and linked list..." << endl;
    //nocsList.appendToCSVAndList(filePath, "NEW", "Newland", "Newlandia", "TestTag", "New note");

    // Print the updated linked list
    //cout << "\nUpdated Linked List Contents:" << endl;
    //nocsList.printList();

    // Delete a row from the CSV and linked list
    cout << "\nDeleting the entry with code 'NEW'..." << endl;
    nocsList.deleteFromCSVAndList(filePath, "NEW");

    // Print the linked list after deletion
    cout << "\nLinked List Contents After Deletion:" << endl;
    nocsList.printList();

    return 0;
}

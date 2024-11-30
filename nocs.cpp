#include "nocs.h"

// Constructor
NocList::NocList() : head(nullptr), tail(nullptr) {}

// Destructor
NocList::~NocList()
{
    while (head)
    {
        Nocs* temp = head;
        head = head->next;
        delete temp;
    }
}

// Add a new node to the linked list
void NocList::addNode(const string& code, const string& country,
                         const string& country_long, const string& tag, const string& note)
{
    Nocs* newNode = new Nocs(code, country, country_long, tag, note);
    if (!head)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}

// Print the linked list
void NocList::printList() const
{
    Nocs* current = head;
    while (current)
    {
        cout << "Code: " << current->code << ", "
             << "Country: " << current->country << ", "
             << "Country Long: " << current->country_long << ", "
             << "Tag: " << current->tag << ", "
             << "Note: " << current->note << endl;
        current = current->next;
    }
}

// Load data from a CSV file
void NocList::loadFromCSV(const string& filePath)
{
    ifstream file(filePath);
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    string line;

    // Skip the header line
    getline(file, line);

    // Read each row of the CSV
    while (getline(file, line))
    {
        stringstream ss(line);
        string code, country, country_long, tag, note;

        // Parse the CSV line
        getline(ss, code, ',');
        getline(ss, country, ',');
        getline(ss, country_long, ',');
        getline(ss, tag, ',');
        getline(ss, note, ',');

        // Add node to the linked list
        addNode(code, country, country_long, tag, note);
    }

    file.close();
}

// Append a new row to the CSV file and linked list
void NocList::appendToCSVAndList(const string& filePath, const string& code, const string& country,
                                    const string& country_long, const string& tag, const string& note)
{
    // Append the new row to the CSV file
    ofstream file(filePath, ios::app); // Open in append mode
    if (!file.is_open())
    {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    file << code << ',' << country << ',' << country_long << ',' << tag << ',' << note << '\n';
    file.close();

    // Add the new row to the linked list
    addNode(code, country, country_long, tag, note);
}

// Delete a row from both the CSV file and the linked list
void NocList::deleteFromCSVAndList(const string& filePath, const string& code)
{
    // Remove the node from the linked list
    Nocs* current = head;
    Nocs* prev = nullptr;

    while (current)
    {
        if (current->code == code)
        {
            if (prev)
            {
                prev->next = current->next;
            }
            else
            {
                head = current->next;
            }
            if (current == tail)
            {
                tail = prev;
            }
            delete current;
            break;
        }
        prev = current;
        current = current->next;
    }

    // Rewrite the CSV file without the deleted row
    ifstream fileIn(filePath);
    if (!fileIn.is_open())
    {
        cerr << "Error opening file: " << filePath << endl;
        return;
    }

    ofstream fileOut("temp.csv");
    if (!fileOut.is_open())
    {
        cerr << "Error creating temporary file." << endl;
        return;
    }

    string line;
    while (getline(fileIn, line))
    {
        stringstream ss(line);
        string rowCode;
        getline(ss, rowCode, ',');

        // Write the line to the temp file if it's not the deleted row
        if (rowCode != code)
        {
            fileOut << line << '\n';
        }
    }

    fileIn.close();
    fileOut.close();

    // Replace the original file with the updated temp file
    remove(filePath.c_str());
    rename("temp.csv", filePath.c_str());
}

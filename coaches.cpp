#include "Coaches.h"
#include <fstream>
#include <sstream>

CoachList::CoachList() : head(nullptr) {}

CoachList::~CoachList()
{
    Coach* current = head;
    while (current)
    {
        Coach* temp = current;
        current = current->next;
        delete temp;
    }
}

void CoachList::insertCoach(const string coachData[])
{
    Coach* newCoach = new Coach
    {
        coachData[0], coachData[1], coachData[2], coachData[3], coachData[4],
        coachData[5], coachData[6], coachData[7], coachData[8], coachData[9],
        coachData[10], nullptr // next pointer set to null
    };

    if (!head)
    {
        head = newCoach;
    }
    else
    {
        Coach* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newCoach;
    }

    ofstream outFile("data/coaches.csv", ios::app); // Open in append mode
    if (outFile.is_open())
    {
        // Write coach data to the file
        outFile << coachData[0] << ',' << coachData[1] << ',' << coachData[2] << ','
                << coachData[3] << ',' << coachData[4] << ',' << coachData[5] << ','
                << coachData[6] << ',' << coachData[7] << ',' << coachData[8] << ','
                << coachData[9] << ',' << coachData[10] << '\n';

        outFile.close();
    }
    else
    {
        cerr << "Error: Could not open coaches.csv for writing.\n";
    }
}

void CoachList::loadFromCSV(const string& filePath)
{
    ifstream file(filePath);
    if (!file.is_open())
    {
        cerr << "Error: Failed to open file: " << filePath << endl;
        return;
    }

    string line;
    getline(file, line); // Skip the header row

    while (getline(file, line))
    {
        istringstream ss(line);
        string value;
        string coachData[11]; // Assuming 11 columns in the CSV
        int index = 0;

        while (getline(ss, value, ','))
        {
            // Trim whitespace (if any)
            value.erase(0, value.find_first_not_of(" \t")); // Trim leading spaces
            value.erase(value.find_last_not_of(" \t") + 1); // Trim trailing spaces

            if (index < 11)
            {
                coachData[index] = value;
                index++;
            }
        }

        // Ensure the row has exactly 11 columns before inserting
        if (index == 11)
        {
            insertCoach(coachData); // Reuse the existing insert function
        }
        else
        {
            cerr << "Warning: Skipping invalid row with " << index
                      << " columns: " << line << endl;
        }
    }

    file.close();
    cout << "File loaded successfully from: " << filePath << endl;
}


void CoachList::displayCoaches() const
{
    Coach* current = head;
    while (current)
    {
        cout << "Code: " << current->code << ", Name: " << current->name
             << ", Country: " << current->country << ", Discipline: " << current->discipline << "\n";
        current = current->next;
    }
}


#ifndef COACHES_H
#define COACHES_H

#include <string>
#include <iostream>

using namespace std;

struct Coach
{
    string code;
    string current;
    string name;
    string name_short;
    string name_tv;
    string gender;
    string function;
    string country_code;
    string country;
    string nationality;
    string discipline;
    Coach* next;
};

class CoachList
{
private:
    Coach* head;

public:
    CoachList();
    ~CoachList();

    void insertCoach(const string coachData[]); // Insert a coach node
    void loadFromCSV(const string& filePath);   // Load coaches from CSV
    void displayCoaches() const;               // Display all coaches
};

#endif // COACHES_H

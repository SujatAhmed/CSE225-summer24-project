//
// Created by sujat on 12/7/24.
//

#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <vector>

using namespace std;

vector<string> split(const string& line, char delimiter); // Splits a string by a delimiter
vector<vector<string>> parseCSV(const string& filename); // Parses a CSV file

#endif // UTILS_H


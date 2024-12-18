

#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

struct Member {
    string name;
    string username;
    string password;
    string adminPassword = "admin123";
    string memberType;
    Member* next;

    Member(string n, string u, string p, string t)
        : name(n), username(u), password(p), memberType(t), next(nullptr) {}
};

class MemberList {
private:
    Member* head; // Linked list head
    const string csvFileName = "members.csv";

    void loadFromCSV();
    void saveToCSV();
    bool usernameExists(const string& username);

public:
    MemberList();
    ~MemberList();

    bool registerMember(string name, string username, string password, string type);
    string loginMember(string username, string password);
    bool deleteMember(string username, string adminPassword);
    void displayMembers();
};

#endif

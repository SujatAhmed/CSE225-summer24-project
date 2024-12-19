
#include "MenuHandler.h"
#include <cstdlib>
#include <limits>

using namespace std;

void MenuHandler::start() {
    MemberList memberList;

    while (true) {
        clearScreen();
        cout << "\n===== Welcome =====\n";
        cout << "1. Login\n2. Register\n3. Exit\nEnter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: loginMember(memberList); break;
            case 2: registerMember(memberList); break;
            case 3: cout << "Goodbye!\n"; exit(0);
            default: cout << "Invalid choice! Try again.\n"; break;
        }
    }
}

void MenuHandler::loginMember(MemberList& memberList) {
    string username, password;

    clearScreen();
    cout << "Login Portal:\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    string memberType = memberList.loginMember(username, password);
    if (memberType == "admin") {
        system("pause");
        adminMenu(memberList);
    } else if (memberType == "user") {
        system("pause");
        userMenu();
    } else {
        cout << "Invalid credentials. Please try again.\n";
        system("pause");
    }
}

void MenuHandler::registerMember(MemberList& memberList) {
    string name, username, password, type;

    clearScreen();
    cout << "Register New Member:\n";
    cout << "Name: ";
    cin >> name;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;
    cout << "Member Type (user/admin): ";
    cin >> type;

    if (memberList.registerMember(name, username, password, type)) {
        cout << "Registration successful!\n";
    } else {
        cout << "Registration failed. Try again.\n";
    }
    system("pause");
}

void MenuHandler::adminMenu(MemberList& memberList) {
    while (true) {
        clearScreen();
        cout << "\n===== Admin Menu =====\n";
        cout << "1. Display Members\n2. Delete Member\n";
        cout << "3. Add Data to CSV" << endl;
        cout << "4. Delete Data" << endl;
        cout << "5. Show Data" << endl;
        cout << "6. Search Data" << endl;
        cout << "7. Logout" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: memberList.displayMembers(); break;
            case 2: {
                string username;
                cout << "Enter Username to Delete: ";
                cin >> username;
                memberList.deleteMember(username);
                break;
            }
            case 3:
                cout << "Adding Data to CSV..." << endl;
                break;
            case 4:
                cout << "Deleting Data..." << endl;
                break;
            case 5:
                showDataSubmenu();
                break;
            case 6:
                searchDataSubmenu();
                break;
            case 7:
                cout << "Logging out...\n";
                system("pause");
                return;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
        system("pause");
    }
}

void MenuHandler::userMenu() {
    while (true) {
        clearScreen();
        cout << "\n===== User Menu =====\n";
        cout << "1. Show Data\n2. Search Data\n3. Logout\nEnter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: showDataSubmenu(); break;
            case 2: searchDataSubmenu(); break;
            case 3:
                cout << "Logging out...\n";
                system("pause");
                return;
            default:
                cout << "Invalid choice! Try again." << endl;
        }
        system("pause");
    }
}

void MenuHandler::showDataSubmenu() {
    clearScreen();
    cout << "\n===== Show Data =====" << endl;
    cout << "1. Athletes Data" << endl;
    cout << "2. Coaches Data" << endl;
    cout << "3. Teams Data" << endl;
    cout << "4. Back" << endl;
    cout << "Enter your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
        case 1:
            cout << "Displaying Athletes Data..." << endl;
            break;
        case 2:
            cout << "Displaying Coaches Data..." << endl;
            break;
        case 3:
            cout << "Displaying Teams Data..." << endl;
            break;
        case 4:
            return;
        default:
            cout << "Invalid choice! Try again." << endl;
    }
    system("pause");
}

void MenuHandler::searchDataSubmenu() {
    while (true) {
        clearScreen();
        cout << "\n===== Search Data =====" << endl;
        cout << "1. Athletes Data" << endl;
        cout << "2. Coaches Data" << endl;
        cout << "3. Teams Data" << endl;
        cout << "4. Back" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
                searchAthletesData();
                break;
            case 2:
                searchCoachesData();
                break;
            case 3:
                searchTeamsData();
                break;
            case 4:
                cout << "Returning to the previous menu...\n";
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
        system("pause");
    }
}

void MenuHandler::searchAthletesData() {
    cout << "Searching for Athletes Data..." << endl;
}

void MenuHandler::searchCoachesData() {
    cout << "Searching for Coaches Data..." << endl;
}

void MenuHandler::searchTeamsData() {
    cout << "Searching for Teams Data..." << endl;
}

void MenuHandler::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

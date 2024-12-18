#include "Member.h"
#include <iostream>
#include <cstdlib>
#include <cstdlib>
#include <windows.h>
#include <limits>
using namespace std;

// Function prototypes
void start();
void registerMember(MemberList& memberList);
void loginMember(MemberList& memberList);
void adminMenu(MemberList& memberList);
void userMenu();
void showDataSubmenu();
void searchDataSubmenu();
void searchAthletesData();
void searchCoachesData();
void searchTeamsData();
void clearScreen();



// Function to start the menu system
void start() {
    MemberList memberList; // Object to manage members

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

// Function to handle login
void loginMember(MemberList& memberList) {
    string username, password;

    clearScreen();
    cout << "Login Portal:\n";
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    string memberType = memberList.loginMember(username, password);
    if (memberType == "admin") {
        adminMenu(memberList);
    } else if (memberType == "user") {
        userMenu();
    } else {
        cout << "Invalid credentials. Please try again.\n";
        system("pause");
    }
}

// Function to handle registration
void registerMember(MemberList& memberList) {
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

// Admin menu
void adminMenu(MemberList& memberList) {
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
                string username, adminPassword;
                cout << "Enter Username to Delete: ";
                cin >> username;
                cout << "Enter Admin Password: ";
                cin >> adminPassword;
                memberList.deleteMember(username, adminPassword);
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

// User menu
void userMenu() {
    while (true) {
        clearScreen();
        cout << "\n===== User Menu =====\n";
        cout << "1. Show Data \n2. Search Data \n3. Logout \nEnter your choice: ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1:
            showDataSubmenu();
            break;

                case 2:
            searchDataSubmenu();
            break;
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


// Show data submenu
void showDataSubmenu()
{
    while (true)
    {
        clearScreen();
        cout << "\n===== Show Data =====" << endl;
        cout << "1. Athletes Data" << endl;
        cout << "2. Coaches Data" << endl;
        cout << "3. Teams Data" << endl;
        cout << "4. Back" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
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
}

// Submenu for search data
void searchDataSubmenu()
{
    while (true)
    {
        clearScreen();
        cout << "\n===== Search Data =====" << endl;
        cout << "1. Athletes Data" << endl;
        cout << "2. Coaches Data" << endl;
        cout << "3. Teams Data" << endl;
        cout << "4. Back" << endl;
        cout << "Enter your choice: ";

        int choice;
        cin >> choice;

        switch (choice)
        {
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
// Placeholder function to search for athletes' data
void searchAthletesData()
{
    cout << "Searching for Athletes Data..." << endl;
    // Implement specific logic for athletes data search
}

// Placeholder function to search for coaches' data
void searchCoachesData()
{
    cout << "Searching for Coaches Data..." << endl;
    // Implement specific logic for coaches data search
}

// Placeholder function to search for teams' data
void searchTeamsData()
{
    cout << "Searching for Teams Data..." << endl;
    // Implement specific logic for teams data search
}


// Clear screen function
void clearScreen() {

    system("cls");
}









// Main function
int main() {
    start();
    return 0;
}

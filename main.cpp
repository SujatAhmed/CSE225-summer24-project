#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <windows.h>
#include <limits>

using namespace std;

// Structure to hold user information
struct User
{
    string name;
    string ID;
    string password;
    string role;
};

// MenuSystem class to handle login, signup, and menus
class MenuSystem
{
private:
    vector<User> users;                   // Stores user information
    const string fileName = "users.csv"; // CSV file for persistent storage

    // Utility function to clear the screen
    void clearScreen()
    {
        system("cls"); // Clear console for Windows
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

    // Search data submenu for different categories
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

    // Search data entry point
    void searchData()
    {
        cout << "Opening Search Data Sub-menu..." << endl;
        system("pause");
        searchDataSubmenu(); // Redirect to the submenu
    }

    // Show data submenu for different categories
    void showDataSubmenu()
    {
        while (true)
        {
            clearScreen();
            cout << "\n===== Show Data Submenu =====" << endl;
            cout << "1. Athletes Data" << endl;
            cout << "2. Coaches Data" << endl;
            cout << "3. Events Data" << endl;
            cout << "4. Medalists Data" << endl;
            cout << "5. Medals Data" << endl;
            cout << "6. Total Medal Data" << endl;
            cout << "7. NOCs Data" << endl;
            cout << "8. Teams Data" << endl;
            cout << "9. Back" << endl;
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
                cout << "Displaying Events Data..." << endl;
                break;
            case 4:
                cout << "Displaying Medalists Data..." << endl;
                break;
            case 5:
                cout << "Displaying Medals Data..." << endl;
                break;
            case 6:
                cout << "Displaying Total Medal Data..." << endl;
                break;
            case 7:
                cout << "Displaying NOCs Data..." << endl;
                break;
            case 8:
                cout << "Displaying Teams Data..." << endl;
                break;
            case 9:
                cout << "Returning to the previous menu...\n";
                return;
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
            system("pause");
        }
    }

public:
    // Constructor: Load users from CSV
    MenuSystem()
    {
        loadUsersFromCSV();
    }

    // Function to start the menu system
    void start()
    {
        while (true)
        {
            clearScreen();
            cout << "\n===== Welcome =====" << endl;
            cout << "1. Login" << endl;
            cout << "2. Register" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                login();
                break;
            case 2:
                registerUser();
                break;
            case 3:
                cout << "Exiting program... Goodbye!" << endl;
                exit(0);
            default:
                cout << "Invalid choice! Please try again." << endl;
            }
        }
    }

    // Load users from CSV file
    void loadUsersFromCSV()
    {
        ifstream file(fileName);
        if (!file)
        {
            cout << "No existing user data found. Starting fresh." << endl;
            return;
        }

        string line;
        while (getline(file, line))
        {
            stringstream ss(line);
            User user;
            getline(ss, user.name, ',');
            getline(ss, user.ID, ',');
            getline(ss, user.password, ',');
            getline(ss, user.role, ',');
            users.push_back(user);
        }
        file.close();
    }

    // Save user to CSV file
    void saveUserToCSV(const User &user)
    {
        ofstream file(fileName, ios::app);
        file << user.name << "," << user.ID << "," << user.password << "," << user.role << endl;
        file.close();
    }

    // Login function
    void login()
    {
        string ID, password;
        clearScreen();
        cout << "Login Portal ->" << endl << endl;

        cout << "Enter ID: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        getline(cin, ID);

        cout << "Enter Password: ";
        getline(cin, password);

        for (User &u : users)
        {
            if (u.ID == ID && u.password == password)
            {
                cout << "\nLogin Successful! Welcome, " << u.name << " (" << u.role << ")\n";
                system("pause");
                if (u.role == "admin")
                {
                    adminMenu();
                }
                else
                {
                    userMenu();
                }
                return;
            }
        }
        cout << "Invalid credentials! Try again." << endl;
        system("pause");
    }

    // Register a new user
    void registerUser()
    {
        User newUser;
        clearScreen();
        cout << "Register User Portal ->" << endl << endl;

        cout << "Enter Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        getline(cin, newUser.name); // Allows spaces in name

        cout << "Enter ID: ";
        cin >> newUser.ID;

        cout << "Enter Password: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
        getline(cin, newUser.password);

        cout << "Enter Role (admin/user): ";
        cin >> newUser.role;

        if (newUser.role != "admin" && newUser.role != "user")
        {
            cout << "Invalid role! Role must be 'admin' or 'user'." << endl;
            system("pause");
            return;
        }

        users.push_back(newUser);
        saveUserToCSV(newUser);
        cout << "Registration successful! You can now login." << endl;
        system("pause");
    }

    // Admin Menu
    void adminMenu()
    {
        while (true)
        {
            clearScreen();
            cout << "\n===== Admin Menu =====" << endl;
            cout << "1. Add Data to CSV" << endl;
            cout << "2. Delete Data" << endl;
            cout << "3. Show Data" << endl; // Submenu for "Show Data"
            cout << "4. Edit Data" << endl;
            cout << "5. Show Analysis" << endl;
            cout << "6. Search Data" << endl;
            cout << "7. Logout" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                cout << "Adding Data to CSV..." << endl;
                break;
            case 2:
                cout << "Deleting Data..." << endl;
                break;
            case 3:
                showDataSubmenu(); // Call the "Show Data" submenu
                break;
            case 4:
                cout << "Editing Data..." << endl;
                break;
            case 5:
                cout << "Showing Data Analysis..." << endl;
                break;
            case 6:
                searchData();
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

    // User Menu
    void userMenu()
    {
        while (true)
        {
            clearScreen();
            cout << "\n===== User Menu =====" << endl;
            cout << "1. Show Data" << endl; // Submenu for "Show Data"
            cout << "2. Show Data Analysis" << endl;
            cout << "3. Search Data" << endl;
            cout << "4. Logout" << endl;
            cout << "Enter your choice: ";

            int choice;
            cin >> choice;

            switch (choice)
            {
            case 1:
                showDataSubmenu(); // Call the "Show Data" submenu
                break;
            case 2:
                cout << "Showing Data Analysis..." << endl;
                break;
            case 3:
                searchData();
                break;
            case 4:
                cout << "Logging out...\n";
                system("pause");
                return;
            default:
                cout << "Invalid choice! Try again." << endl;
            }
            system("pause");
        }
    }
};

// Main function
int main()
{
    MenuSystem menuSystem;
    menuSystem.start();
    return 0;
}

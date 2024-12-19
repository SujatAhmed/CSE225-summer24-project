

#ifndef MENUHANDLER_H
#define MENUHANDLER_H

#include "MemberList.h"
#include <iostream>
#include <string>

class MenuHandler {
public:
    void start();

private:
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
};

#endif // MENUHANDLER_H

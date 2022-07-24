#include <iostream>
#include "System.hpp"

using std::cin, std::string, std::cout;

int System::bugCounter = 0;

void System::reportBug(string_view description) 
{
    bugs.report( Bug( bugCounter++, string(description), 0, 0, 0, 0, signedUpUser) );
}

void System::assignBugToUser() {
    printBugChooser();
    printUserChooser();
}

void System::markBugAsSolved() {
    printBugChooser();
}

void System::login(string_view username, string_view password) 
{
    
}

void System::printBugChooser() {
}

void System::printUserChooser() {
    
}

string System::printUsernameInput()
{
    string username;
    cout << "Username: ";
    cin >> username;
    return username;
}

string System::printPasswordInput() 
{
    // entered charactered need to be replaced with ***
    return "";
}

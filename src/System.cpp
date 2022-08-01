#include <iostream>
#include <cstdio>
#include "Authenticator.hpp"
#include "System.hpp"

using std::cin, std::string, std::cout;

int System::bugCounter = 0;

void System::reportBug(string_view description)
{
    bugs.report( Bug( bugCounter++, string(description), 0, 0, 0, 0, currentUser ) );
}

void System::assignBugToUser() {
    printBugChooser();
    printUserChooser();
}

void System::markBugAsSolved() {
    printBugChooser();
}

void System::login() 
{
    string username = requestUsername();
    string password = requestPassword();
    Authenticator auth;
    
    if (auth.login(username, password)) {
        // TODO : using out of scope shared pointer causes segmentation fault!
        currentUser = std::make_shared<User>( User(username) );
        std::cout << "Successfully signed in.\n";
    } else {
        std::cout << "Failed to sign in, incorrect credentials were given.\n";
    }

}

void System::printBugChooser() {
}

void System::printUserChooser() {
    
}

string System::requestUsername()
{
    string username;
    cout << "Username: ";
    cin >> username;
    return username;
}

string System::requestPassword() 
{
    char* password;
    password = getpass("Password: ");
    return string(password);
}

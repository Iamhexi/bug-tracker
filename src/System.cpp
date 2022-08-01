#include <iostream>
#include <cstdio>
#include "Authenticator.hpp"
#include "System.hpp"

using std::cin, std::string, std::cout;

int System::bugCounter = 0;

void System::reportBug(string_view description)
{
    bugs.report( Bug( bugCounter++, string(description), 0, 0, 0, 0, currentUser->username ) );
}

void System::assignBugToSolver() 
{
    bugPtr bug = printBugChooser();
    userPtr user = printUserChooser();
    bugs.assignToProgrammer(bug, user);
}

void System::markBugAsSolved() 
{
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

void System::signUp()
{
    string username = requestUsername();
    string password = requestPassword();
    Authenticator auth;
    
    if (auth.signUp(username, password)) {
        // TODO : using out of scope shared pointer causes segmentation fault!
        currentUser = std::make_shared<User>( User(username) );
        std::cout << "Successfully registered.\n";
    } else {
        std::cout << "Failed to register, a user with the given username already exists.\n";
    }
}

bugPtr System::printBugChooser() 
{
    // TODO
    // load all bugs from database
    // print unassigned bugs
    // let user choose one of them
    // return the chosen bug

    return std::make_shared<Bug>();
}

userPtr System::printUserChooser() 
{
    // TODO
    // load all users from database
    // print all users
    // let user choose one of them
    // return the chosen user
    return std::make_shared<User>("EMPTY USER");
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

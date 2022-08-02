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
    bugPtr solvedBug = printBugChooser();
    solvedBug->markAsSolved();
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

bugPtr System::printBugChooser(BugStatus bugStatus) 
{
    bugList existingBugs = bugs.getSimplifiedList(bugStatus);
    for(auto& bug: existingBugs)
        std::cout << bug.id << "\t" << bug.description << "\t" << "[STATUS]" << "\n";
    
    int choice;
    std::cout << "Enter bug ID to choose it: ";
    std::cin >> choice;

    return bugs.find(choice);
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

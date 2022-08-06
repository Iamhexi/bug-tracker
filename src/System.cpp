#include <iostream>
#include <cstdio>
#include "Authenticator.hpp"
#include "System.hpp"

using std::cin, std::string, std::cout;

void System::reportBug()
{
    constexpr size_t maxDecriptionSize = 5000;
    constexpr char delimiter = '#';

    char descriptionLine[maxDecriptionSize];

    cout<< "Describe the bug (use " << delimiter << " at the end): ";
    cin.getline(descriptionLine, maxDecriptionSize, delimiter);
    string description = string(descriptionLine);
    description = description.substr(1, description.size()-1); // remove first-character endline

    Bug bug(0, description);
    bug.report(currentUser->username);
    bugs.report(bug);
}

void System::assignBugToSolver() 
{
    Bug& bug = printBugChooser(BugStatus::Open);
    userPtr user = printUserChooser(UserRole::Programmer);
    bugs.assignToProgrammer(bug, user, currentUser->username);

    
}

void System::markBugAsSolved() 
{
    Bug& solvedBug = printBugChooser(BugStatus::In_progress);
    bugs.markAsSolved(solvedBug);

    solvedBug.markAsSolved();
}

void System::login() 
{
    string username = requestUsername();
    string password = requestPassword();
    Authenticator auth;
    
    if (auth.login(username, password)) {
        UserRole role = auth.getUserRole(username);
        currentUser = User::create(role, username);
        // TODO Change programmer to the dynamically chosen class
        cout << "Successfully signed in.\n";
        return;
    } else {
        cout << "Failed to sign in, incorrect credentials were given. Try again. \n";
    }
}

void System::signUp()
{
    string username = requestUsername();
    string password = requestPassword();
    Authenticator auth;
    
    if (auth.signUp(username, password)) {
        currentUser = User::create(UserRole::Programmer, username);
        // TODO Change programmer to the dynamically chosen class
        cout << "Successfully registered.\n";
    } else {
        cout << "Failed to register, a user with the given username already exists.\n";
    }
}

Bug& System::printBugChooser(BugStatus bugStatus)
{
    bugList existingBugs = bugs.getSimplifiedList(bugStatus);

    cout << "ID\tDescription\tStatus\n";
    for(auto& bug: existingBugs)
        cout << bug.id << "\t" << bug.description << "\t" << convertBugStatusToString(bug.status) << "\n";
    
    int choice;
    cout << "Enter bug ID to choose it: ";
    cin >> choice;

    return bugs.find(choice);
}

void System::printBugs(BugStatus status) const
{
    bugList existingBugs = bugs.getSimplifiedList(status);
    cout << "ID\tDescription\n";
    for(auto& bug: existingBugs)
        cout << bug.id << "\t" << bug.description << "\n";
    cout << '\n';
}

userPtr System::printUserChooser(UserRole role) const
{
    UserManager userManager;
    usersSummary allUsers = userManager.getUsersSummary(role);

    cout << "Username\tRole\n";
    for(auto& userSummary: allUsers)
        cout << userSummary.first << "\t" << convertUserRoleToString(userSummary.second) << "\n";

    string choice;
    cout << "Enter username to choose them: ";
    cin >> choice;

    return userManager.find(choice);
}

string System::requestUsername() const
{
    string username;
    cout << "Username: ";
    cin >> username;
    return username;
}

string System::requestPassword() const
{
    char* password;
    password = getpass("Password: ");
    return string(password);
}

bool System::isUserSignedIn() const
{
    return currentUser != nullptr;
}

UserRole System::getUserRole() const
{
    return currentUser->getUserRole();
}
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
<<<<<<< HEAD
    bugPtr bug = printBugChooser(BugStatus::Open);
=======
    Bug& bug = printBugChooser(BugStatus::Open);
>>>>>>> development
    userPtr user = printUserChooser(UserRole::Programmer);
    bugs.assignToProgrammer(bug, user, currentUser->username);

    
}

void System::markBugAsSolved() 
{
<<<<<<< HEAD
    bugPtr solvedBug = printBugChooser(BugStatus::In_progress);
    bugs.markAsSolved(*solvedBug);

    solvedBug->markAsSolved();
=======
    Bug& solvedBug = printBugChooser(BugStatus::In_progress);
    bugs.markAsSolved(solvedBug);

    solvedBug.markAsSolved();
>>>>>>> development
}

void System::login() 
{
<<<<<<< HEAD
    while (true)
    {
        string username = requestUsername();
        string password = requestPassword();
        Authenticator auth;
        
        if (auth.login(username, password)) {
            currentUser = std::make_shared<User>( User(username) );
            cout << "Successfully signed in.\n";
            break;
        } else {
            cout << "Failed to sign in, incorrect credentials were given. Try again. \n";
        }
=======
    string username = requestUsername();
    string password = requestPassword();
    Authenticator auth;
    
    if (auth.login(username, password)) {
        UserRole role = auth.getUserRole(username);
        currentUser = User::create(role, username);
        
        if (currentUser != nullptr) {
            cout << "You are " << username <<  " [" << convertUserRoleToString(role) << "].\n";
            return;
        } else {
            cout << "You signed in correctly but your role is incorrect. Exitting...\n";
            exit(0);
        }
    } else {
        cout << "Failed to sign in, incorrect credentials were given. Try again. \n";
>>>>>>> development
    }
}

void System::signUp()
{
    string username = requestUsername();
    string password = requestPassword();
    Authenticator auth;
    
    if (auth.signUp(username, password)) {
<<<<<<< HEAD
        currentUser = std::make_shared<User>( User(username) );
=======
        currentUser = User::create(UserRole::Programmer, username);
        // TODO Change programmer to the dynamically chosen class
>>>>>>> development
        cout << "Successfully registered.\n";
    } else {
        cout << "Failed to register, a user with the given username already exists.\n";
    }
}

<<<<<<< HEAD
bugPtr System::printBugChooser(BugStatus bugStatus) 
=======
Bug& System::printBugChooser(BugStatus bugStatus)
>>>>>>> development
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

<<<<<<< HEAD
void System::printBugs(BugStatus status)
{
    bugList existingBugs = bugs.getSimplifiedList(status);
    cout << "ID\tDescription\t";
=======
void System::printBugs(BugStatus status) const
{
    bugList existingBugs = bugs.getSimplifiedList(status);
    cout << "ID\tDescription\n";
>>>>>>> development
    for(auto& bug: existingBugs)
        cout << bug.id << "\t" << bug.description << "\n";
    cout << '\n';
}

<<<<<<< HEAD
userPtr System::printUserChooser(UserRole role) 
{
    // TODO 
=======
userPtr System::printUserChooser(UserRole role) const
{
>>>>>>> development
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

<<<<<<< HEAD
string System::requestUsername()
=======
string System::requestUsername() const
>>>>>>> development
{
    string username;
    cout << "Username: ";
    cin >> username;
    return username;
}

<<<<<<< HEAD
string System::requestPassword() 
=======
string System::requestPassword() const
>>>>>>> development
{
    char* password;
    password = getpass("Password: ");
    return string(password);
}

<<<<<<< HEAD
bool System::isSignedIn() const
{
    return currentUser != nullptr;
}
=======
bool System::isUserSignedIn() const
{
    return currentUser != nullptr;
}

UserRole System::getUserRole() const
{
    return currentUser->getUserRole();
}
>>>>>>> development

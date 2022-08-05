#include "Menu.hpp"
#include <cstdlib>

void Menu::init()
{
    authorise();
    showGodModeMenu();
}

void Menu::showProgrammerMenu()
{
    int choice;
    do {
        cout << "\n\nMenu:\n";
        cout << "1 - Show bugs available to solve.\n";
        cout << "2 - Mark the bug as solved.\n";
        cout << "3 - Report a new bug.\n";
        cout << "0 - Exit and save changes\n.";
        // TODO: programmer should be able to mark as solved only be they are working on, not any bug 
        
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0)
            exit(0);
        else if (choice == 1)
            system.printBugs(BugStatus::Open);
        else if (choice == 2)
            system.markBugAsSolved();
        else if (choice == 3)
            system.reportBug();
        else
            cout << unknownCommandMessage;
    } while(choice != 0);
}

void Menu::showTesterMenu()
{
    int choice;
    do {
        cout << "\n\nMenu:\n";
        cout << "1 - Report a new bug.\n";
        cout << "2 - Show already reported bugs.\n";
        cout << "3 - Show bugs that are being fixed.\n";
        cout << "0 - Exit and save changes.\n";

        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0)
            exit(0);
        else if (choice == 1)
            system.reportBug();
        else if (choice == 2)
            system.printBugs(BugStatus::Open);
        else if (choice == 3)
            system.printBugs(BugStatus::In_progress);
        else 
            cout << unknownCommandMessage;
    } while(choice != 0);
}

void Menu::showManagerMenu()
{
    int choice;
    do {
        cout << "\n\nMenu:\n";
        cout << "1 - Show reported bugs.\n";
        cout << "2 - Assign a new task to a programmer.\n";
        cout << "3 - Show bugs are being fixed.\n";
        cout << "4 - Show closed bug reports.\n";
        cout << "0 - Exit and save changes\n.";
        
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0)
            exit(0);
        else if (choice == 1)
            system.printBugs(BugStatus::Open);
        else if (choice == 2)
            system.assignBugToSolver();
        else if (choice == 3)
            system.printBugs(BugStatus::In_progress);
        else if (choice == 4)
            system.printBugs(BugStatus::Closed);
        else 
            cout << unknownCommandMessage;
    } while(choice != 0);
}

void Menu::showGodModeMenu()
{
    int choice;
    do {
        cout << "\n\nMenu:\n";
        cout << "1 - Report a new bug.\n";
        cout << "2 - Assign a solver for a bug.\n";
        cout << "3 - Mark a bug as solved.\n";
        cout << "4 - Show open bugs.\n";
        cout << "5 - Show bugs which solution is in progress.\n";
        cout << "6 - Show closed bugs.\n";
        cout << "0 - Exit and save changes.\n";
        
        cout << "Your choice: ";
        cin >> choice;
        
        if (choice == 0)
            exit(0);
        else if (choice == 1)
            system.reportBug();
        else if (choice == 2)
            system.assignBugToSolver();
        else if (choice == 3)
            system.markBugAsSolved();
        else if (choice == 4)
            system.printBugs(BugStatus::Open);
        else if (choice == 5)
            system.printBugs(BugStatus::In_progress);
        else if (choice == 6)
            system.printBugs(BugStatus::Closed);
        else 
            cout << unknownCommandMessage;
    } while(choice != 0);
}

void Menu::authorise()
{
    int choice; 
    do {
        cout << "\n\nMenu:\n";
        cout << "1 - Sign in.\n";
        cout << "2 - Create a new account.\n";
        cout << "0 - Exit.\n";
        
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 0)
            exit(0);
        else if (choice == 1)
            system.login();
        else if (choice == 2)
            system.signUp();
        else
            cout << unknownCommandMessage; 


    } while( !system.isUserSignedIn() );
}

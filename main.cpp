#include "src/System.hpp"

int main()
{

    /* 
    1) options 4. and 5. don't work
    2) UserManager.getUsersSummary returns incomplete list
    */

    System system;
    int choice;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. - login\n";
        std::cout << "2. - registration\n";
        std::cout << "3. - report a new bug\n";
        std::cout << "4. - assign a solver for a bug\n";
        std::cout << "5. - mark bug as solved\n";
        std::cout << "6. - show open bugs\n";
        std::cout << "7. - show bugs which are being solved\n";
        std::cout << "8. - show closed bugs\n";
        std::cout << "0. - exit\n";
        
        std::cout << "Your choice: ";
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            system.login();
            break;
        
        case 2:
            system.signUp();
            break;

        case 3:
            system.reportBug();
            break;

        case 4:
            system.assignBugToSolver();
            break;

        case 5:
            system.markBugAsSolved();
            break;

        case 6:
            system.printBugs(BugStatus::Open);
            break;

        case 7:
            system.printBugs(BugStatus::In_progress);
            break;

        case 8:
            system.printBugs(BugStatus::Closed);
            break;

        case 0:
            break;
        }
    } while(choice != 0);

    
    return 0;
}
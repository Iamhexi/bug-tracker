#include "src/System.hpp"

int main()
{

    System system;
    int choice;

    do {
        std::cout << "Menu:\n";
        std::cout << "1. - login\n";
        std::cout << "2. - registration\n";
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
            system.markBugAsSolved();
            break;

        case 0:
            break;
        }
    } while(choice != 0);

    
    return 0;
}
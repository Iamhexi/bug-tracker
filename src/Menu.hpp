#include "System.hpp"

using std::string, std::cin, std::cout;

class Menu 
{
private:
    System system;
    const char* unknownCommandMessage = "It seems like you entered an incorrect option. Try again\n";
public:
    void init();
private:
    void showInitialPanel();
    void showGodModeMenu();
    void showProgrammerMenu();
    void showTesterMenu();
    void showManagerMenu();
};
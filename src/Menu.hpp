#include "System.hpp"

using std::string, std::cin, std::cout;

class Menu 
{
private:
    System system;
    static constexpr string_view unknownCommandMessage {"It seems like you entered an incorrect option. Please, try again.\n"};
public:
    void authorise();
    void showAppropriateMenu();
private:
    void showGodModeMenu();
    void showProgrammerMenu();
    void showTesterMenu();
    void showManagerMenu();
};
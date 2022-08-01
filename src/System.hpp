#include <iostream>
#include <memory>
#include <string_view>
#include <string>
#include "User.hpp"
#include "BugManager.hpp"

using std::string_view, std::string;
using bugPtr = std::shared_ptr<Bug>;


class System
{
private:
    userPtr currentUser = nullptr; // null to indicate being not logged in
    BugManager bugs;
public:
    static int bugCounter;
public:
    void reportBug(string_view description);
    void assignBugToUser(); // prompts to choose a bug from window, then from a user choosing window
    void markBugAsSolved(); // prompts to choose a bug choosing window
    void login();
    void signUp();
private:
    void printBugChooser(); // TODO return type to BugPtr
    void printUserChooser(); // TODO change return type to UserPtr
    string requestUsername();
    string requestPassword();
};
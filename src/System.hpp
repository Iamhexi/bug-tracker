#include <iostream>
#include <memory>
#include <string_view>
#include "User.hpp"
#include "BugManager.hpp"

using std::string_view;
using userPtr = std::unique_ptr<User>;
using bugPtr = std::shared_ptr<Bug>;

class System
{
private:
    userPtr signedUpUser; // null to indicate being not logged in
    BugManager bugs;
public:
    System();
    void reportBug(string_view description); // refactor to string_view
    void assignBugToUser(); // prompts to choose a bug from window, then from a user choosing window
    void markBugAsSolved(); // prompts to choose a bug choosing window
    void login(string_view username, string_view password); // shows a text fields to give username and password
private:
    void printBugChooser();
    void printUserChooser();
    void printUsernameInput();
    void printPasswordInput();
};
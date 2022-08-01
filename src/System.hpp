#include <iostream>
#include <memory>
#include <string_view>
#include <string>
#include "User.hpp"
#include "BugManager.hpp"

using std::string_view, std::string;
using bugPtr = std::shared_ptr<Bug>;
using userPtr = std::shared_ptr<User>;

class System
{
private:
    userPtr currentUser = nullptr; // null to indicate being not logged in
    BugManager bugs;
public:
    static int bugCounter;
public:
    void reportBug(string_view description);
    void assignBugToSolver(); // prompts to choose a bug from window, then from a user choosing window
    void markBugAsSolved(); // prompts to choose a bug choosing window
    void login();
    void signUp();
private:
    bugPtr printBugChooser();
    userPtr printUserChooser();
    string requestUsername();
    string requestPassword();
};
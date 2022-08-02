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
    void reportBug();
    void assignBugToSolver(); // prompts to choose a bug from window, then from a user choosing window
    void markBugAsSolved();
    void login();
    void signUp();
private:
    bugPtr printBugChooser(BugStatus bugStatus = BugStatus::all);
    userPtr printUserChooser();
    string requestUsername();
    string requestPassword();
};
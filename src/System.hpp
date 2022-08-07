#pragma once
#include <iostream>
#include <memory>
#include <string_view>
#include <string>
#include "User.hpp"
#include "BugManager.hpp"
#include "Bug.hpp"

using std::string_view, std::string;
using bugPtr = std::shared_ptr<Bug>;
using userPtr = std::shared_ptr<User>;

class System
{
private:
    userPtr currentUser = nullptr; // null to indicate being not logged in
    BugManager bugs;
public:
    void reportBug();
    void assignBugToSolver();
    void markBugAsSolved();
    void login();
    void signUp();
<<<<<<< HEAD
    void printBugs(BugStatus status);
    bool isSignedIn() const;
private:
    bugPtr printBugChooser(BugStatus bugStatus = BugStatus::All);
    userPtr printUserChooser(UserRole role = UserRole::All);
    string requestUsername();
    string requestPassword();
=======
    void printBugs(BugStatus status) const;
    bool isUserSignedIn() const;
    UserRole getUserRole() const;
private:
    Bug& printBugChooser(BugStatus bugStatus = BugStatus::All);
    userPtr printUserChooser(UserRole role = UserRole::All) const;
    string requestUsername() const;
    string requestPassword() const;
>>>>>>> development
};
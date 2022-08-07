#pragma once
#include <vector>
#include "Programmer.hpp"
#include "Bug.hpp"
#include "Database.hpp"
<<<<<<< HEAD

using userPtr = std::shared_ptr<User>;
using bugPtr = std::shared_ptr<Bug>;
=======
#include "BugNullObject.hpp"

using userPtr = std::shared_ptr<User>;
>>>>>>> development
using bugList = std::vector<SimplifiedBug>;

class BugManager
{
private:
    std::vector<Bug> bugs;
public:
    BugManager();
<<<<<<< HEAD
    void report(const Bug bug);
    void markAsSolved(const Bug& assignedBug);
    void assignToProgrammer(bugPtr assignedBug, userPtr programmer, string managerUsername);
    bugList getSimplifiedList(BugStatus status = BugStatus::All);
    bugPtr find(int bugId);
=======
    void report(Bug& bug);
    void markAsSolved(const Bug& assignedBug);
    void assignToProgrammer(Bug& assignedBug, userPtr programmer, string managerUsername);
    bugList getSimplifiedList(BugStatus status = BugStatus::All) const;
    Bug& find(int bugId);
>>>>>>> development
    ~BugManager();

private:
    void uploadLocalDatabaseToRemoteDatabase();
};
#pragma once
#include <vector>
#include "Programmer.hpp"
#include "Bug.hpp"
#include "Database.hpp"
#include "BugNullObject.hpp"

using userPtr = std::shared_ptr<User>;
using bugList = std::vector<SimplifiedBug>;

class BugManager
{
private:
    std::vector<Bug> bugs;
public:
    BugManager();
    void report(Bug& bug);
    void markAsSolved(const Bug& assignedBug);
    void assignToProgrammer(Bug& assignedBug, userPtr programmer, string managerUsername);
    bugList getSimplifiedList(BugStatus status = BugStatus::All) const;
    Bug& find(int bugId);
    ~BugManager();

private:
    void uploadLocalDatabaseToRemoteDatabase();
};
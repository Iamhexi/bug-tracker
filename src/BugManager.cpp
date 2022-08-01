#include "BugManager.hpp"

BugManager::BugManager()
{
    Database db;
    bugs = db.getBugVector("SELECT * FROM bugs;");
}

void BugManager::report(const Bug bug) 
{
    bugs.push_back(bug);
}

void BugManager::markAsSolved(const Bug& solvedBug) 
{
    for(Bug& bug: bugs)
        if (bug == solvedBug)
            bug.markAsSolved();
}

void BugManager::assignToProgrammer(bugPtr assignedBug, userPtr programmer)
{
    for(Bug& bug: bugs)
        if (std::make_shared<Bug>(bug) == assignedBug)
            bug.assign(programmer->username);
}

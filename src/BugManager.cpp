#include "BugManager.hpp"

BugManager::BugManager()
{
    Database db;
    bugs = db.getBugVector("SELECT * FROM bugs;");
}

void BugManager::report(const Bug bug) 
{
    bugs.push_back(bug);
    // TODO
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

bugList BugManager::getSimplifiedList(BugStatus status)
{
    bugList list;
    for(auto& bug: bugs)
    {
        if (bug.getStatus() == status || status == BugStatus::all) {
            list.emplace_back(bug.id, bug.description, bug.getStatus());
        }
    }

    return list;
}

bugPtr BugManager::find(int bugId)
{
    for(auto& bug: bugs)
        if (bug.id == bugId)
            return std::make_shared<Bug>(bug);
    
    return std::make_shared<Bug>(Bug());
}
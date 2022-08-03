#include "BugManager.hpp"
#include <iostream>
#include <fmt/core.h>

BugManager::BugManager()
{
    Database db;
    bugs.reserve(5000);
    bugs = db.getBugVector("SELECT * FROM bugs;");
}

void BugManager::report(const Bug bug) 
{
    Database db;

    bugs.push_back(bug);

    db.execute(
        string("INSERT INTO bugs VALUES (NULL, '") + 
        bug.description + "', " + std::to_string(bug.reportedAt)  + ", " +
        std::to_string(bug.assignedAt) + ", " + std::to_string(bug.solvedAt) + ", '" +
        bug.reportedBy + "', '" + bug.assignedBy + "', '" +
        bug.assignedTo + "');"
    );
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

void BugManager::uploadLocalDatabaseToRemoteDatabase()
{
    // TODO: fix me
    // data takes brom bug& isn't marked as solved when it was marked as solved by system
    // e.g. bug.solvedAt == 0 after shared_ptr to bug -> markAsSolved()

    Database db;
    for(auto& bug: bugs)
    {
        string sql = fmt::format(
            "UPDATE bugs SET assignedAt = {0}, solvedAt = {1}, assignedBy = '{2}', assignedTo = '{3}' WHERE id = {4};",
            bug.assignedAt, bug.solvedAt, bug.assignedBy, bug.assignedTo, bug.id
        );

        db.execute(sql);

    }
}

BugManager::~BugManager()
{
    uploadLocalDatabaseToRemoteDatabase();
}
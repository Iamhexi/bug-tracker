#include "BugManager.hpp"
#include <iostream>
#include <fmt/core.h>

BugManager::BugManager()
{
    Database db;
    bugs = db.getBugVector("SELECT * FROM bugs;");
}

void BugManager::report(Bug& bug)
{
    Database db;

    bug.report(bug.reportedBy); // assign time

    bugs.push_back(bug);

    db.execute( fmt::format(
        "INSERT INTO bugs VALUES (NULL, '{0}', {1}, {2}, {3}, '{4}', '{5}', '{6}');",
        bug.description, bug.reportedAt, bug.assignedAt, bug.solvedAt,
        bug.reportedBy, bug.assignedBy, bug.assignedTo
    ) );
}

void BugManager::markAsSolved(const Bug& solvedBug) 
{
    for(Bug& bug: bugs)
    {
        if (bug == solvedBug)
        {
            Database db;
            bug.markAsSolved();
            string sql = fmt::format(
                "UPDATE bugs SET solvedAt = {0} WHERE id = {1};",
                bug.solvedAt, bug.id
            );
            db.execute(sql);
            return;
        }
    }
    std::cout << "No bug has been marked as solved although markAsSolved() method had been invoked\n";

}

void BugManager::assignToProgrammer(Bug& assignedBug, userPtr programmer, string managerUsername)
{
    if (programmer == nullptr) {
        std::cout << "Cannot assign bug to a non-existent user.\n";
        return;
    }


    for(Bug& bug: bugs)
    {
        if (bug == assignedBug) {
            if (bug.getStatus() == BugStatus::Open) {
                std::cout << "The task with ID " << bug.id << " has been assigned to " << programmer->username << "\n";
                bug.assign(programmer->username, managerUsername);
                return;
            } else if (bug.getStatus() == BugStatus::In_progress) {
                std::cout << "The task with ID " << bug.id << " has been REASSIGNED to " << programmer->username << "\n";
                bug.assign(programmer->username, managerUsername);
                return;
            }

        }

    }

        std::cout << "No user has been assigned although assignToProgrammer() had been invoked\n";
}

bugList BugManager::getSimplifiedList(BugStatus status) const
{
    bugList list;
    for(auto& bug: bugs)
    {
        if (bug.getStatus() == status || status == BugStatus::All) {
            list.emplace_back(bug.id, bug.description, bug.getStatus());
        }
    }

    return list;
}

Bug& BugManager::find(int bugId)
{
    for(Bug& bug: bugs)
        if (bug.id == bugId)
            return bug;
    
    return bugNullObject;
}

void BugManager::uploadLocalDatabaseToRemoteDatabase()
{
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
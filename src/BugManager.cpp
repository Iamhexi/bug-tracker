#include "BugManager.hpp"
#include <iostream>
#include <fmt/core.h>

BugManager::BugManager()
{
    Database db;
    bugs = db.getBugVector("SELECT * FROM bugs;");
}

void BugManager::report(const Bug bug) 
{
    Database db;

    bugs.push_back(bug);

    db.execute( fmt::format(
        "INSERT INTO bugs VALUES (NULL, '{0}', {1}, {2}, {3}, '{4}', '{5}', '{6}');",
        bug.description, bug.reportedAt, bug.assignedAt, bug.solvedAt,
        bug.reportedBy, bug.assignedBy, bug.assignedTo
    ) );
}

void BugManager::markAsSolved(const Bug& solvedBug) 
{

    std::cout << "size of bugs vector " << bugs.size() << "\n";
    for(Bug& bug: bugs)
    {
        if (bug == solvedBug)
        {
            Database db;
            bug.markAsSolved();
            std::cout << "Bug with id = " << bug.id << " marked as solved.\n";
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

void BugManager::assignToProgrammer(bugPtr assignedBug, userPtr programmer, string managerUsername)
{
    std::cout << "Number of bugs: " << bugs.size() << "\n";

    for(Bug& bug: bugs)
    {
        if (bug == *assignedBug) {
            if (bug.getStatus() == BugStatus::open) {
                std::cout << "The task with ID " << bug.id << " has been assigned to " << programmer->username << "\n";
                bug.assign(programmer->username, managerUsername);
                return;
            } else if (bug.getStatus() == BugStatus::in_progress) {
                std::cout << "The task with ID " << bug.id << " has been REASSIGNED to " << programmer->username << "\n";
                bug.assign(programmer->username, managerUsername);
                return;
            }

        }

    }

        std::cout << "No user has been assigned although assignToProgrammer() had been invoked\n";
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
    Database db;
    for(auto& bug: bugs)
    {
        std::cout << bug.id << "\t" << bug.assignedBy << "\t" << bug.assignedTo << "\n";

        string sql = fmt::format(
            "UPDATE bugs SET assignedAt = {0}, solvedAt = {1}, assignedBy = '{2}', assignedTo = '{3}' WHERE id = {4};",
            bug.assignedAt, bug.solvedAt, bug.assignedBy, bug.assignedTo, bug.id
        );

        std::cout << sql << "\n";

        if (db.execute(sql))
            std::cout << "UPDATED!\n";
        else {
            std::cout << "Unable to upload the local db to the remote db.\n";
        }

    }
}

BugManager::~BugManager()
{
    uploadLocalDatabaseToRemoteDatabase();
}
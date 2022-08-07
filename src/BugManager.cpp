#include "BugManager.hpp"
#include <iostream>
#include <fmt/core.h>

BugManager::BugManager()
{
    Database db;
    bugs = db.getBugVector("SELECT * FROM bugs;");
}

<<<<<<< HEAD
void BugManager::report(const Bug bug) 
{
    Database db;

=======
void BugManager::report(Bug& bug)
{
    Database db;

    bug.report(bug.reportedBy); // assign time

>>>>>>> development
    bugs.push_back(bug);

    db.execute( fmt::format(
        "INSERT INTO bugs VALUES (NULL, '{0}', {1}, {2}, {3}, '{4}', '{5}', '{6}');",
        bug.description, bug.reportedAt, bug.assignedAt, bug.solvedAt,
        bug.reportedBy, bug.assignedBy, bug.assignedTo
    ) );
}

void BugManager::markAsSolved(const Bug& solvedBug) 
{
<<<<<<< HEAD

    std::cout << "size of bugs vector " << bugs.size() << "\n";
=======
>>>>>>> development
    for(Bug& bug: bugs)
    {
        if (bug == solvedBug)
        {
            Database db;
            bug.markAsSolved();
<<<<<<< HEAD
            std::cout << "Bug with id = " << bug.id << " marked as solved.\n";
=======
>>>>>>> development
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

<<<<<<< HEAD
void BugManager::assignToProgrammer(bugPtr assignedBug, userPtr programmer, string managerUsername)
{
    std::cout << "Number of bugs: " << bugs.size() << "\n";

    for(Bug& bug: bugs)
    {
        if (bug == *assignedBug) {
=======
void BugManager::assignToProgrammer(Bug& assignedBug, userPtr programmer, string managerUsername)
{
    for(Bug& bug: bugs)
    {
        if (bug == assignedBug) {
>>>>>>> development
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

<<<<<<< HEAD
bugList BugManager::getSimplifiedList(BugStatus status)
=======
bugList BugManager::getSimplifiedList(BugStatus status) const
>>>>>>> development
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

<<<<<<< HEAD
bugPtr BugManager::find(int bugId)
{
    for(auto& bug: bugs)
        if (bug.id == bugId)
            return std::make_shared<Bug>(bug);
    
    return std::make_shared<Bug>(Bug());
=======
Bug& BugManager::find(int bugId)
{
    for(Bug& bug: bugs)
        if (bug.id == bugId)
            return bug;
    
    return bugNullObject;
>>>>>>> development
}

void BugManager::uploadLocalDatabaseToRemoteDatabase()
{
    Database db;
    for(auto& bug: bugs)
    {
<<<<<<< HEAD
        std::cout << bug.id << "\t" << bug.assignedBy << "\t" << bug.assignedTo << "\n";

=======
>>>>>>> development
        string sql = fmt::format(
            "UPDATE bugs SET assignedAt = {0}, solvedAt = {1}, assignedBy = '{2}', assignedTo = '{3}' WHERE id = {4};",
            bug.assignedAt, bug.solvedAt, bug.assignedBy, bug.assignedTo, bug.id
        );

<<<<<<< HEAD
        std::cout << sql << "\n";

        if (db.execute(sql))
            std::cout << "UPDATED!\n";
        else {
            std::cout << "Unable to upload the local db to the remote db.\n";
        }
=======
        db.execute(sql);
>>>>>>> development

    }
}

BugManager::~BugManager()
{
    uploadLocalDatabaseToRemoteDatabase();
}
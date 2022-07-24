#include "BugManager.hpp"


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

void BugManager::assignToProgrammer(const Bug& assignedBug, const Programmer& programmer) 
{
    for(Bug& bug: bugs)
        if (bug == assignedBug)
            bug.assign(programmer);
}

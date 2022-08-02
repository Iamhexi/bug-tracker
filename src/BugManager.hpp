#include <vector>
#include "Programmer.hpp"
#include "Bug.hpp"
#include "Database.hpp"

using userPtr = std::shared_ptr<User>;
using bugPtr = std::shared_ptr<Bug>;
using bugList = std::vector<SimplifiedBug>;

class BugManager
{
private:
    std::vector<Bug> bugs;
public:
    BugManager();
    void report(const Bug bug);
    void markAsSolved(const Bug& assignedBug);
    void assignToProgrammer(bugPtr, userPtr programmer);
    bugList getSimplifiedList(BugStatus status = BugStatus::all);
    bugPtr find(int bugId);
    ~BugManager();
private:
    void uploadLocalDatabaseToRemoteDatabase();
};
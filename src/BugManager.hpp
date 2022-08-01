#include <vector>
#include "Programmer.hpp"
#include "Bug.hpp"
#include "Database.hpp"

using userPtr = std::shared_ptr<User>;
using bugPtr = std::shared_ptr<Bug>;

class BugManager
{
private:
    std::vector<Bug> bugs;
public:
    BugManager();
    void report(const Bug bug);
    void markAsSolved(const Bug& assignedBug);
    void assignToProgrammer(bugPtr, userPtr programmer);
};
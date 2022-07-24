#include <vector>
#include "Programmer.hpp"
#include "Bug.hpp"


class BugManager
{
private:
    std::vector<Bug> bugs;
public:
    void report(const Bug bug);
    void markAsSolved(const Bug& assignedBug);
    void assignToProgrammer(const Bug& assignedBug, const Programmer& programmer);
};
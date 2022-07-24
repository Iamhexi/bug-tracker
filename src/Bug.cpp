#include "Bug.hpp"

Bug::Bug(int id,
    std::string description,
    datetime reportedAt,
    datetime assignedAt,
    datetime solvedAt,

    userPtr reportedBy,
    userPtr assignedBy,
    userPtr assignedTo)
    : id(id), reportedAt(reportedAt), assignedAt(assignedAt),
      reportedBy(reportedBy), assignedBy(assignedBy), assignedTo(assignedTo)
{

}

void Bug::report(userPtr reportedBy)
{
  reportedAt = getCurrentTime();
  this->reportedBy = reportedBy;
}

void Bug::assign(Programmer programmer)
{
  assignedAt = getCurrentTime();
  assignedTo = std::make_unique<Programmer>(programmer);
}

void Bug::markAsSolved()
{
  solvedAt = getCurrentTime();
}

bool Bug::operator==(const Bug& bug)
{
  return this->id == bug.id;
}

double Bug::getCurrentTime()
{
  // TODO implement this method
  return 0;
}
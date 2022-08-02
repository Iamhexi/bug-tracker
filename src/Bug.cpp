#include "Bug.hpp"
#include <chrono>

Bug::Bug(int id,
    std::string description,
    datetime reportedAt,
    datetime assignedAt,
    datetime solvedAt,

    string reportedBy,
    string assignedBy,
    string assignedTo)
    : id(id), reportedAt(reportedAt), assignedAt(assignedAt),
      reportedBy(reportedBy), assignedBy(assignedBy), assignedTo(assignedTo)
{

}

void Bug::report(string reportedBy)
{
  reportedAt = getCurrentTime();
  this->reportedBy = reportedBy;
}

void Bug::assign(string programmer)
{
  assignedAt = getCurrentTime();
  assignedTo = programmer;
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
  const auto p1 = std::chrono::system_clock::now();
  return std::chrono::duration_cast<std::chrono::seconds>( p1.time_since_epoch() ).count();
}

BugStatus Bug::getStatus()
{
  if (solvedAt > 0L)
    return BugStatus::closed;
  else if (assignedAt > 0L)
    return BugStatus::in_progress;
  else if (reportedAt > 0L)
    return BugStatus::open;
  else
    return BugStatus::uninitialised;
}

SimplifiedBug::SimplifiedBug(
        int id,
        string description,
        BugStatus status
    ):
  id(id), description(description), status(status)
{

}
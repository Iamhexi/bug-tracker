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
    : id(id), description(description), reportedAt(reportedAt),
      assignedAt(assignedAt), solvedAt(solvedAt),
      reportedBy(reportedBy), assignedBy(assignedBy), assignedTo(assignedTo)
{

}

void Bug::report(string reportedBy)
{
  reportedAt = getCurrentTime();
  this->reportedBy = reportedBy;
}

void Bug::assign(string programmer, string manager)
{
  assignedBy = manager;
  assignedTo = programmer;
  assignedAt = getCurrentTime();
}

void Bug::markAsSolved()
{
  solvedAt = getCurrentTime();
}

bool Bug::operator==(const Bug& bug) const
{
  return this->id == bug.id;
}

double Bug::getCurrentTime() const
{
  const auto p1 = std::chrono::system_clock::now();
  return std::chrono::duration_cast<std::chrono::seconds>( p1.time_since_epoch() ).count();
}

BugStatus Bug::getStatus() const
{
  if (solvedAt > 0L)
    return BugStatus::Closed;
  else if (assignedAt > 0L)
    return BugStatus::In_progress;
  else if (reportedAt > 0L)
    return BugStatus::Open;
  else
    return BugStatus::Uninitialised;
}

SimplifiedBug::SimplifiedBug(
        int id,
        string description,
        BugStatus status
    ):
  id(id), description(description), status(status)
{

}

std::string convertBugStatusToString(BugStatus role)
{
    switch (role)
    {
    case BugStatus::Uninitialised:
        return "Uninitialised";
        break;

    case BugStatus::Open:
        return "Open";
        break;

    case BugStatus::In_progress:
        return "In progress";
        break;

    case BugStatus::Closed:
        return "Closed";
        break;

    case BugStatus::All:
        return "All bugs statuses";
        break;
    
    default:
        return "Unknown status";
        break;
    }
}
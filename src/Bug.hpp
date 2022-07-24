#include <chrono>
#include <cstdint>
#include <memory>
#include "Programmer.hpp"

using datetime = double;
using userPtr = std::shared_ptr<User>;

struct Bug
{
public:
    Bug(int id,
    datetime reportedAt,
    datetime assignedAt,
    datetime solvedAt,

    userPtr reportedBy,
    userPtr assignedBy,
    userPtr assignedTo);
   
    int id;
    datetime reportedAt;
    datetime assignedAt;
    datetime solvedAt;

    userPtr reportedBy;
    userPtr assignedBy;
    userPtr assignedTo;

    void report(userPtr reportedBy);
    void assign(Programmer programmer);
    void markAsSolved();

    bool operator==(const Bug& bug);
private:
    double getCurrentTime();
};
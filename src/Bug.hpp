#include <chrono>
#include <cstdint>
#include <memory>
#include <string>
#include "Programmer.hpp"

using datetime = double;
using userPtr = std::shared_ptr<User>;

struct Bug
{
    static constexpr datetime datetimeZero = 0.L;
public:
    Bug(int id = 0,
    std::string description = static_cast<std::string>(""),
    datetime reportedAt = datetimeZero,
    datetime assignedAt = datetimeZero,
    datetime solvedAt = datetimeZero,

    userPtr reportedBy = nullptr,
    userPtr assignedBy = nullptr,
    userPtr assignedTo = nullptr);
   
    int id;
    std::string description;
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
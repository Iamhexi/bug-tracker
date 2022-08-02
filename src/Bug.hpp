#pragma once
#include <chrono>
#include <cstdint>
#include <memory>
#include <string>
#include "Programmer.hpp"

using datetime = double;
using std::string;

enum class BugStatus
{
    uninitialised,
    open,
    in_progress,
    closed,
    all
};

struct Bug
{
    static constexpr datetime datetimeZero = 0.L;
public:
    Bug(int id = 0,
    std::string description = static_cast<std::string>(""),
    datetime reportedAt = datetimeZero,
    datetime assignedAt = datetimeZero,
    datetime solvedAt = datetimeZero,

    string reportedBy = static_cast<std::string>(""),
    string assignedBy = static_cast<std::string>(""),
    string assignedTo = static_cast<std::string>(""));
   
    int id;
    std::string description;
    datetime reportedAt;
    datetime assignedAt;
    datetime solvedAt;

    string reportedBy;
    string assignedBy;
    string assignedTo;

    void report(string reportedBy);
    void assign(string programmer);
    void markAsSolved();

    bool operator==(const Bug& bug);
    BugStatus getStatus();
private:
    double getCurrentTime();
};


struct SimplifiedBug
{
public:
    SimplifiedBug(
        int id = 0,
        string description = static_cast<string>(""),
        BugStatus status = BugStatus::uninitialised
    );
public:
    int id;
    string description;
    BugStatus status;
};

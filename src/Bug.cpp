#include "Bug.hpp"

int Bug::idCounter = 0;

Bug::Bug()
{
    id = Bug::idCounter++;
    //reportDate = std::chrono::system_clock::now(); // assign current time
}
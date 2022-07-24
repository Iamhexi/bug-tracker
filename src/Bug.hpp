#include <chrono>
#include "User.hpp"
#include <memory>

using datetime = std::chrono::duration<double>;


struct Bug
{
public:
    Bug();
    static int idCounter;
    int id;
    datetime reportDate;
    std::shared_ptr<User> reportedBy;

};
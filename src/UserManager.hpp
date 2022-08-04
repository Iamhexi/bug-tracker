#pragma once
#include "BugManager.hpp"
#include <memory>
#include <string>
#include <vector>
#include <map>

using usersSummary = std::map<std::string, UserRole>;
using userPtr = std::shared_ptr<User>;

// The class retrieves users from DB and can get list of usernames and their corresponding roles.

class UserManager
{
private:
    usersSummary users;
public:
    UserManager();
    usersSummary getUsersSummary(UserRole role = UserRole::All);
    userPtr find(string username);
};
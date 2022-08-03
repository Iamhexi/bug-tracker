#pragma once
#include "User.hpp"
#include "UserRole.hpp"
#include <string>
#include <vector>
#include <map>

using usersSummary = std::map<std::string, UserRole>;

// The class retrieves users from DB and can get list of usernames and their corresponding roles.

class UserManager
{
private:
    std::vector<User> users;
public:
    UserManager();
    usersSummary getUsersSummary(UserRole role = UserRole::All);
    
};
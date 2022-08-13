#pragma once
#include "BugManager.hpp"
#include <memory>
#include <string>
#include <vector>
#include <map>

using userPtr = std::shared_ptr<User>;
using userVector = std::vector<userPtr>;

// The class retrieves users from DB and can get list of usernames and their corresponding roles.

class UserManager
{
private:
    std::vector<userPtr> users;
public:
    UserManager();
    userVector downloadUserListFromDatabase(UserRole role = UserRole::All);
    userPtr find(string_view username);
};
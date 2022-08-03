#pragma once
#include "UserManager.hpp"
#include "Database.hpp"

UserManager::UserManager()
{

}

usersSummary UserManager::getUsersSummary(UserRole role)
{
    // TODO: implement
    // returns all users' usernames and roles with the given role
    Database db;
    int userRoleAsInt = static_cast<int>(role);
    if (userRoleAsInt != 0)
        db.getUsersSummary("SELECT * FROM credentials WHERE role = " +
        std::to_string(userRoleAsInt) + ";");
    else
        db.getUsersSummary("SELECT * FROM credentials;");
}
#include "UserManager.hpp"
#include "Database.hpp"
#include <iostream>
#include <fmt/core.h>

UserManager::UserManager()
{
    users = downloadUserListFromDatabase();
}

userVector UserManager::downloadUserListFromDatabase(UserRole role)
{
    Database db;
    string sql {};

    if (role == UserRole::All) {
        sql = fmt::format("SELECT login, hashedPassword, role FROM credentials;");
    } else {
        int userRoleAsInteger = static_cast<int>(role);
        sql = fmt::format(
            "SELECT login, hashedPassword, role FROM credentials WHERE role = {0};", userRoleAsInteger
        );
    }

    return db.getUserVector(sql);
}

userPtr UserManager::find(string_view username)
{
    for(auto& user: users){
        if (user->username == username) 
            return User::create(UserRole::Programmer, username);
    }
    
    return User::create(UserRole::None, "USER NOT FOUND");
}
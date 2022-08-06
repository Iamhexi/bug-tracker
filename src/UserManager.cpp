#include "UserManager.hpp"
#include "Database.hpp"
#include <iostream>

UserManager::UserManager()
{
    users = getUsersSummary();
}

usersSummary UserManager::getUsersSummary(UserRole role)
{

    Database db;
    string sql;
    int userRoleAsInt = static_cast<int>(role);
    if (role != UserRole::All){
        sql = string("SELECT login, role FROM credentials WHERE role = ") +
        std::to_string(userRoleAsInt) + ";";

        return db.getUsersSummary(sql);
    } else {
        sql = "SELECT login, role FROM credentials;";
        return db.getUsersSummary(sql);

    }
}

userPtr UserManager::find(string username)
{
    for(auto& user: users){
        if (user.first == username) 
        // TODO: HASH string and then compare them for perfomance
            return User::create(UserRole::Programmer, username);
    }
    
    return User::create(UserRole::Programmer, "USER NOT FOUND");
}
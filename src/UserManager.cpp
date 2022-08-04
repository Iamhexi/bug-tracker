#include "UserManager.hpp"
#include "Database.hpp"
#include <iostream>

UserManager::UserManager()
{

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
    for(auto& user: users)
        if (user.username == username) 
        // TODO: HASH string and then compare them for perfomance
            return std::make_shared<User>(user);
    
    return std::make_shared<User>("USER NOT FOUND");
 }
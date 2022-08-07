#include "Authenticator.hpp"
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>
<<<<<<< HEAD
=======
#include <fmt/core.h>

using namespace std::literals;
>>>>>>> development

Authenticator::Authenticator()
{
    loadCredentialsFromDatabase();
}

void Authenticator::loadCredentialsFromDatabase()
{
    Database db;
    credentials = db.getCredentialsMap("SELECT login, hash FROM credentials;");
}

bool Authenticator::login(string_view username, string_view password)
{
    try {
        return std::to_string( hash(password) ) == credentials.at( string(username) );
    } catch (std::exception& e){
        return false;
    }
}

bool Authenticator::signUp(string_view username, string_view password)
{
    Database db;
    string hashedPassword = std::to_string( hash(password) );
    UserRole defaultRole = UserRole::Manager;

<<<<<<< HEAD
    return db.execute(string("INSERT INTO credentials VALUES ('") + string(username) + "', '" 
    + hashedPassword + "', " + std::to_string(static_cast<int>(defaultRole)) + ");");
}

=======
    return db.execute(
        fmt::format(
            "INSERT INTO credentials VALUES ('{0}', '{1}', {2});",
            username, hashedPassword, static_cast<int>(defaultRole)
        )
    );
    
  
}

UserRole Authenticator::getUserRole(string_view username)
{
    Database db;
    return db.getUserRole("SELECT role FROM credentials WHERE login = '"s + string(username) + "';");
}
>>>>>>> development

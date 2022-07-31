#include "Authenticator.hpp"
#include <iostream>
#include <iomanip>
#include <functional>
#include <string>
#include <unordered_set>

Authenticator::Authenticator()
{
    loadCredentialsFromDatabase();
}

void Authenticator::loadCredentialsFromDatabase()
{
    Database db;
    credentials = db.getRows("SELECT * FROM credentials;");
}

bool Authenticator::login(string_view username, string_view password)
{
    try {
        std::cout << "From db: " << credentials.at(string(username)) << "\n";
        std::cout << "From user: " << hash(password);

        return std::to_string( hash(password) ) == credentials.at( string(username) );
    } catch (std::exception e){
        return false;
    }
}

bool Authenticator::signUp(string_view username, string_view password)
{
    Database db;
    string hashedPassword = std::to_string( hash(password) );
    return db.execute(string("INSERT INTO credentials VALUES ('") + string(username) + "', '" + hashedPassword + "');");
}


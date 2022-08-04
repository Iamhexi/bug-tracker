#pragma once    
#include <iostream>
#include <string_view>
#include "Database.hpp"

using std::string_view, std::string, std::map;

class Authenticator
{
private:
    std::hash<string_view> hash;
    map<string, string> credentials;
public:
    Authenticator();
    bool login(string_view username, string_view password);
    bool signUp(string_view username, string_view password);
private:
    void loadCredentialsFromDatabase();
};
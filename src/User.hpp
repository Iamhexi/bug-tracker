#pragma once
#include <string>
#include <string_view>

using std::string, std::string_view;

class User
{
public:
    string username;

    User(string_view username)
    {
        this->username = username;
    }
};
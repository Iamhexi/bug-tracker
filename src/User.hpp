#pragma once
#include <string>
#include <string_view>
#include <iostream>

class User
{
public:
    std::string username;

    User(std::string_view username)
    {
        this->username = username;
    }

    bool operator==(const User& user)
    {
        return user.username == username;
    }
};
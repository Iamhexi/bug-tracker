#pragma once
#include "UserRole.hpp"
#include <string>
#include <string_view>
#include <iostream>
#include <memory>

using std::string, std::string_view;

class User
{
public:
    string username {};
    string hashedPassword {};
    UserRole role = UserRole::None;
public:
    User(string_view username, string_view hashedPassword);
    virtual ~User() = default;
    bool operator==(const User& user);

    virtual UserRole getUserRole() const = 0;
    static std::shared_ptr<User> create(
        UserRole role,
        string_view username,
        string_view hashedPassword = ""
    );
};
#pragma once
#include "UserRole.hpp"
#include <string>
#include <string_view>
#include <iostream>
#include <memory>

class User
{
public:
    std::string username;
public:
    User(std::string_view username);
    virtual ~User() = default;
    bool operator==(const User& user);

    virtual UserRole getUserRole() const = 0;
    static std::shared_ptr<User> create(UserRole role, std::string_view username);
};
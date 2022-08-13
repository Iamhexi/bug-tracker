#pragma once
#include "User.hpp"

class Manager: public User
{
public:
    Manager(string_view username, string_view hashedPassword);
    virtual UserRole getUserRole() const override;
};
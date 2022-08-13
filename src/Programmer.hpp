#pragma once
#include "User.hpp"

class Programmer: public User
{
public:
    Programmer(string_view username, string_view hashedPassword);
    virtual UserRole getUserRole() const override;
};
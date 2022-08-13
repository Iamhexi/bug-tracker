#pragma once
#include "User.hpp"

class Tester: public User
{
public:
    Tester(string_view username, string_view hashedPassword);
    virtual UserRole getUserRole() const override;
};
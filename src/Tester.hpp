#pragma once
#include "User.hpp"

class Tester: public User
{
public:
    Tester(std::string_view username);
    virtual UserRole getUserRole() const override;
};
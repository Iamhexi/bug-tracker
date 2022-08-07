#pragma once
#include "User.hpp"

class Manager: public User
{
public:
    Manager(std::string_view username);
    virtual UserRole getUserRole() const override;
};
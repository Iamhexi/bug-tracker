#pragma once
#include "User.hpp"

class Root: public User
{
public:
    Root(std::string_view username);
    virtual UserRole getUserRole() const override;
};
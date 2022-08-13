#pragma once
#include "User.hpp"

class Root: public User
{
public:
    Root(string_view username, string_view hashedPassword);
    virtual constexpr UserRole getUserRole() const override;
};
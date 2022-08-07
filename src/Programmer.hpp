#pragma once
#include "User.hpp"

class Programmer: public User
{
<<<<<<< HEAD
=======
public:
    Programmer(std::string_view username);
    virtual UserRole getUserRole() const override;
>>>>>>> development
};
<<<<<<< HEAD
=======
#pragma once
>>>>>>> development
#include "User.hpp"

class Manager: public User
{
<<<<<<< HEAD

=======
public:
    Manager(std::string_view username);
    virtual UserRole getUserRole() const override;
>>>>>>> development
};
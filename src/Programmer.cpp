#include "Programmer.hpp"

Programmer::Programmer(string_view username, string_view hashedPassword) 
    : User(username, hashedPassword) {}

UserRole Programmer::getUserRole() const
{
    return UserRole::Programmer;
}
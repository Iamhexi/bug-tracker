#include "Manager.hpp"

Manager::Manager(string_view username, string_view hashedPassword) 
    : User(username, hashedPassword) {}

UserRole Manager::getUserRole() const
{
    return UserRole::Manager;
}
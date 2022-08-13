#include "Root.hpp"

Root::Root(string_view username, string_view hashedPassword) 
    : User(username, hashedPassword) {}

constexpr UserRole Root::getUserRole() const
{
    return UserRole::Root;
}
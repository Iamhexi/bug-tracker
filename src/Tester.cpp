#include "Tester.hpp"

Tester::Tester(string_view username, string_view hashedPassword) 
    : User(username, hashedPassword) {}

UserRole Tester::getUserRole() const
{
    return UserRole::Tester;
}
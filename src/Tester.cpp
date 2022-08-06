#include "Tester.hpp"

Tester::Tester(std::string_view username) : User(username)
{

}

UserRole Tester::getUserRole() const
{
    return UserRole::Tester;
}
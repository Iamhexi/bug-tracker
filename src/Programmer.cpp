#include "Programmer.hpp"

Programmer::Programmer(std::string_view username) : User(username)
{

}

UserRole Programmer::getUserRole() const
{
    return UserRole::Programmer;
}
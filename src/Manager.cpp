#include "Manager.hpp"

Manager::Manager(std::string_view username) : User(username)
{

}

UserRole Manager::getUserRole() const
{
    return UserRole::Manager;
}
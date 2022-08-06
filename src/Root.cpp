#include "Root.hpp"

Root::Root(std::string_view username) : User(username)
{

}

UserRole Root::getUserRole() const
{
    return UserRole::Root;
}
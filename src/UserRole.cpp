#include "UserRole.hpp"

std::string convertUserRoleToString(UserRole role)
{
    switch (role)
    {
    case UserRole::None:
        return "None";
        break;

    case UserRole::All:
        return "Each roles";
        break;

    case UserRole::Programmer:
        return "Programmer";
        break;

    case UserRole::Manager:
        return "Manager";
        break;

    case UserRole::Tester:
        return "Tester";
        break;

    case UserRole::Root:
        return "Administrator";
        break;
    
    default:
        return "Unknown role";
        break;
    }
}
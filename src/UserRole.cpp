#include "UserRole.hpp"

std::string convertUserRoleToString(UserRole role)
{
    switch (role)
    {
    case UserRole::None:
        return "None";
        break;

    case UserRole::All:
<<<<<<< HEAD
        return "Each roles";
=======
        return "Any role";
>>>>>>> development
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
<<<<<<< HEAD
=======

    case UserRole::Root:
        return "Administrator";
        break;
>>>>>>> development
    
    default:
        return "Unknown role";
        break;
    }
}
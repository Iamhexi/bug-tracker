#pragma once
#include <string>

enum class UserRole
{
    None = -1,
    All = 0,
    Manager = 1,
    Programmer = 2,
    Tester = 3,
    Root = 4
};

std::string convertUserRoleToString(UserRole role);

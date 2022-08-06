#include "User.hpp"
#include "Tester.hpp"
#include "Programmer.hpp"
#include "Manager.hpp"

User::User(std::string_view username)
{
    this->username = username;
}

bool User::operator==(const User& user)
{
    return user.username == username;
}

std::shared_ptr<User> User::create(UserRole role, std::string_view username)
{
    switch(role)
    {
        case UserRole::Tester:
            return std::make_shared<Tester>( Tester(username) );
            break;

        case UserRole::Programmer:
            return std::make_shared<Programmer>( Programmer(username) );
            break;

        case UserRole::Manager:
            return std::make_shared<Manager>( Manager(username) );
            break;
    }

    return nullptr;
}
#include "User.hpp"
#include "Tester.hpp"
#include "Programmer.hpp"
#include "Manager.hpp"
#include "Root.hpp"

User::User(string_view username, string_view hashedPassword)
    : username(username), hashedPassword(hashedPassword) {}

bool User::operator==(const User& user)
{
    return user.username == username;
}

std::shared_ptr<User> User::create(UserRole role, string_view username, string_view hashedPassword)
{
    switch(role)
    {
        case UserRole::Tester:
            return std::make_shared<Tester>( Tester(username, hashedPassword) );
            break;

        case UserRole::Programmer:
            return std::make_shared<Programmer>( Programmer(username, hashedPassword) );
            break;

        case UserRole::Manager:
            return std::make_shared<Manager>( Manager(username, hashedPassword) );
            break;

        case UserRole::Root:
            return std::make_shared<Root>( Root(username, hashedPassword) );

        default:
            return nullptr;
    }

}
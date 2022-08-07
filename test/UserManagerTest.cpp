#include <gtest/gtest.h>
#include "../src/UserManager.hpp"
#include <iostream>

TEST(UserManagerTest, TestFindingAnExistingUser)
{
    UserManager u;
    
    ASSERT_NE(u.find("igor"), nullptr);
}

TEST(UserManagerTest, TestNotFindingNotExistingUser)
{
    UserManager u;
    
    ASSERT_NE(u.find("jojo"), nullptr);
}

TEST(UserManagerTest, TestModyfingUser)
{
    UserManager u;
    auto user = u.find("igor");

    user->username = "nono";

    // the second expression creates a new user
<<<<<<< HEAD
    ASSERT_EQ(u.find("nono"), std::make_shared<User>("nono"));
=======
    ASSERT_EQ(u.find("nono"), User::create(UserRole::None, "nono"));
>>>>>>> development
}

TEST(UserManagerTest, TestModyfingUserAndSavingChanges)
{
    // TODO user manager doesn't save its users changes
    UserManager u;

    auto user = u.find("igor");
    user->username = "nono";

<<<<<<< HEAD
    ASSERT_EQ(u.find("igor"), std::make_shared<User>("USER NOT FOUND"));
=======
    ASSERT_EQ(u.find("igor"), User::create(UserRole::None, "USER NOT FOUND"));
>>>>>>> development
}
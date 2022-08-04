#include <gtest/gtest.h>
#include "../src/Authenticator.hpp"

TEST(SignInTest, SigingInAsRegisteredUser)
{
    Authenticator auth;

    bool success = auth.login("igor", "123");

    ASSERT_TRUE(success);
}
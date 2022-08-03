#include <gtest/gtest.h>
#include "../src/Bug.hpp"

TEST(BugTest, TestMarkingBugAsSolved)
{
    Bug bug;

    bug.markAsSolved();

    ASSERT_EQ(BugStatus::closed, bug.getStatus());
}

TEST(BugTest, TestReportingBug)
{
    Bug bug;
    
    bug.report("Username");
    
    ASSERT_EQ(BugStatus::open, bug.getStatus());
}

TEST(BugTest, TestAssigningBug)
{
    Bug bug;

    bug.assign("Username");

    ASSERT_EQ(BugStatus::in_progress, bug.getStatus());

}

TEST(BugTest, TestEqualityOperatorWhenEqual )
{
    Bug bug1(1);
    Bug bug2(bug1);

    ASSERT_TRUE(bug1 == bug2);
}

TEST(BugTest, TestEqualityOperatorWhenInequal )
{
    Bug bug1(1);
    Bug bug2(2);

    ASSERT_FALSE(bug1 == bug2);
}
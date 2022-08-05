#include <gtest/gtest.h>
#include "../src/BugManager.hpp"


TEST(BugManagerTest, TestReportingNewBug)
{
    BugManager manager;
    Bug bug(200, "Bug description");

    manager.report(bug);
    auto& reportedBug = manager.find(bug.id);

    ASSERT_EQ(BugStatus::Open, reportedBug.getStatus());
}

TEST(BugManagerTest, TestMarkingBugAsSolved)
{
    BugManager manager;
    Bug bug(900, "Bug description");
    manager.report(bug);

    auto& existingBug = manager.find(bug.id);
    manager.markAsSolved(existingBug);

    ASSERT_EQ(BugStatus::Closed, existingBug.getStatus());
}

TEST(BugManagerTest, TestAssigningBugToProgrammer)
{
    BugManager manager;
    UserManager userManager;
    auto existingUser = userManager.find("igor");
    Bug bug(100, "Bug description");
    manager.report(bug);

    auto& existingBug = manager.find(bug.id);
    manager.assignToProgrammer(existingBug, existingUser, "Manager username");

    ASSERT_EQ(BugStatus::Closed, existingBug.getStatus());
}
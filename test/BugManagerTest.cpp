#include <gtest/gtest.h>
#include "../src/BugManager.hpp"
#include <algorithm>

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

TEST(BugManagerTest, TestFindingBugWhilstThereIsNoBug)
{
    BugManager manager;
    constexpr int nonExistentBugId = -11;
    
    auto& foundBug = manager.find(nonExistentBugId);

    ASSERT_EQ(bugNullObject, foundBug);
}

TEST(BugManagerTest, TestFindingBugWhilstThereIsBug)
{
    BugManager manager;
    constexpr int existentBugId = 1; 
    Bug bug(existentBugId);
    manager.report(bug);

    auto& foundBug = manager.find(bug.id);

    ASSERT_EQ(bug, foundBug);
}

TEST(BugManagerTest, TestGettingOpenBugsFromSimplifiedList)
{
    BugManager manager;

    Bug openBug1(5, "Open Bug");
    Bug openBug2(6, "Open Bug");

    openBug1.report("Reporter");
    openBug2.report("Reporter");

    manager.report(openBug1);
    manager.report(openBug2);

    auto simplifiedList = manager.getSimplifiedList(BugStatus::Open);

    unsigned int counter {0};
    for (auto& bug: simplifiedList)
        if (bug.status == BugStatus::Open)
            counter++;

    ASSERT_GE(counter, 2);
}


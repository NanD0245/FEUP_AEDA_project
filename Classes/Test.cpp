#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "SystemNetwork.h"

using namespace std;
using testing::Eq;


TEST(test,a_highways) {
    SystemNetwork system;
    ASSERT_TRUE(system.createHighway("A1"));
    ASSERT_TRUE(system.createHighway("a1"));
    ASSERT_EQ(system.createHighway("A2"),true);
    ASSERT_EQ(system.createHighway("a2"), true);
    ASSERT_EQ(system.createHighway("A2"),false);
    system.readHighways();
    ASSERT_TRUE(system.updateHighway(3,"A3"));
    system.readHighways();
    ASSERT_TRUE(system.deleteHighway(2));
    system.readHighways();
}







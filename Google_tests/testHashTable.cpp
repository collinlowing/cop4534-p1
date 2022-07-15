//
// Created by cel on 6/23/22.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../HashTable.hpp"
#include "MockNode.hpp"


// get data
TEST(HashTableTests, mockNode) {
    MockNode node;
    std::string key = "password";
    int expectedHash = std::hash<std::string>{}(key);

    EXPECT_CALL(node, hash())
        .Times(testing::AtLeast(1))
        .WillRepeatedly(testing::Return(expectedHash));

    int testedHash = node.hash();
    EXPECT_EQ(testedHash, expectedHash);
}
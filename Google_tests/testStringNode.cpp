//
// Created by cel on 6/23/22.
//

#include "gtest/gtest.h"
#include "../StringNode.hpp"

// get data
TEST(StringNodeTests, getData) {
    std::string expectedResult = "collin";
    StringNode node("collin", "password");
    std::string data = node.getData();
    EXPECT_EQ(data, expectedResult);
}

// get key
TEST(StringNodeTests, getKey) {
    std::string expectedResult = "password";
    StringNode node("collin", "password");
    std::string key = node.getKey();
    EXPECT_EQ(key, expectedResult);
}

// get next pointer
TEST(StringNodeTests, nextPointer) {
    auto* nextPtr = new StringNode();
    StringNode node;
    node.setNext(nextPtr);
    EXPECT_EQ(node.getNext(), nextPtr);
    delete nextPtr;
}

// make hash key
TEST(StringNodeTests, hash) {
    std::size_t expectedResult = 1746176491;
    StringNode node("collin", "password");
    int hash = node.hash();
    EXPECT_EQ(hash, expectedResult);
}
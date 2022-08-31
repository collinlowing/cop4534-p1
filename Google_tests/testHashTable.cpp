//
// Created by cel on 6/23/22.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../StringHashTable.hpp"


// tests add node and search
TEST(HashTableTests, TestSearchNode) {
    std::size_t numBuckets = 11;
    StringHashTable hashTable(numBuckets);
    std::string data = "name";
    std::string key = "password";

    hashTable.add(data, key);

    StringNode* searchedNode;
    searchedNode = hashTable.search(key);
    std::string expectedKey = searchedNode->getKey();

    EXPECT_EQ(expectedKey, key);
}

// test remove with chained nodes

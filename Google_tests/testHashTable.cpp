//
// Created by cel on 6/23/22.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../StringHashTable.hpp"


// tests add node and search
TEST(HashTableTests, searchNode) {
    StringNode *searchedNode;
    std::size_t numBuckets = 11;
    StringHashTable hashTable(numBuckets);
    std::string data = "name";
    std::string key = "password";

    hashTable.add(data, key);

    searchedNode = hashTable.search("wrong");
    EXPECT_EQ(searchedNode, nullptr);

    searchedNode = hashTable.search(key);
    std::string expectedKey = searchedNode->getKey();
    EXPECT_EQ(expectedKey, key);
}

// test remove with chained nodes
TEST(HashTableTests, removeNode) {
    std::size_t numBuckets = 11;
    StringHashTable hashTable(numBuckets);
    std::string data = "name";
    std::string key = "password";

    hashTable.add(data, key);

    StringNode *searchedNode;
    searchedNode = hashTable.search(key);

    EXPECT_NE(searchedNode, nullptr);

    hashTable.remove(key);
    searchedNode = hashTable.search(key);

    EXPECT_EQ(searchedNode, nullptr);
}

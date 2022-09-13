//
// Created by cel on 6/23/22.
//

#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../StringHashTable.hpp"


// tests add node and search
TEST(HashTableTests, searchNode) {
/*StringNode *searchedNode;
std::size_t numBuckets = 11;
StringHashTable hashTable(numBuckets);
std::string data = "name";
std::string key = "password";

hashTable.add(data, key);

searchedNode = hashTable.search("wrong");
EXPECT_EQ(searchedNode, nullptr);

searchedNode = hashTable.search(key);
std::string expectedKey = searchedNode->getKey();
EXPECT_EQ(expectedKey, key);*/
}

// tests add multiple nodes and search
TEST(HashTableTests, multipleNodes) {
    StringNode *searchedNode;
    std::size_t numBuckets = 1;
    StringHashTable hashTable(numBuckets);
    std::string data1 = "name";
    std::string key1 = "password";
    std::string data2 = "name2";
    std::string key2 = "password2";

    hashTable.add(data1, key1);
    hashTable.add(data2, key2);

    searchedNode = hashTable.search("wrong");
    EXPECT_TRUE(searchedNode == nullptr);

    searchedNode = hashTable.search(key2);
    ASSERT_FALSE(searchedNode == nullptr);
    std::string expectedKey = searchedNode->getKey();
    EXPECT_EQ(expectedKey, key2);
}

/*
// test remove with chained nodes
TEST(HashTableTests, removeNode) {
    std::size_t numBuckets = 11;
    StringHashTable hashTable(numBuckets);
    std::string data = "name";
    std::string key = "password";
    StringNode *searchedNode1 = nullptr;
    StringNode *searchedNode2 = nullptr;

    hashTable.add(data, key);


    searchedNode1 = hashTable.search(key);

    EXPECT_FALSE(searchedNode1 == nullptr);

    hashTable.remove(key);
    searchedNode2 = hashTable.search(key);

    std::cout << searchedNode2 << std::endl;

    EXPECT_TRUE(searchedNode2 == nullptr);
}
*/

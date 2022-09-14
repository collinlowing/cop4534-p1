/***************************************************************
  Student Name: Collin Lowing
  File Name: StringHashTable.hpp
  Project 1

  Externally chained hashtable that stores two strings in a StringNode
***************************************************************/

#ifndef P1_HASHTABLE_H
#define P1_HASHTABLE_H

#include <vector>
#include <stdexcept>
#include <cstddef>
#include "StringNode.hpp"
#include "StringHasher.hpp"

class StringHashTable {
private:
    std::size_t TABLE_SIZE;
    StringNode **table;
public:
    StringHashTable(std::size_t size);  // initializes hashtable max size

    std::size_t hash(std::string key);  // gets hash value

    void add(std::string data, std::string key);    // adds a set of two strings to table

    StringNode *search(std::string key);    // gets a node from table using the key value

    ~StringHashTable(); // cleans up memory
};

#endif //P1_HASHTABLE_H

//
// Created by cel on 6/13/22.
//

#ifndef P1_HASHTABLE_H
#define P1_HASHTABLE_H

/*
 * Template hash table that stores any class with a defined hashing function
 *
 * Requires an item class that holds a data class and key class.
 *
 */

#include <vector>
#include <stdexcept>
#include <cstddef>
#include "StringNode.hpp"
#include "StringHasher.hpp"

class StringHashTable {
private:
    std::size_t numBuckets;
    StringNode *table;
public:
    StringHashTable(std::size_t numBuckets);

    std::size_t hash(std::string key);

    void add(std::string data, std::string key);

    bool remove(std::string key);

    StringNode *search(std::string key);

    ~StringHashTable();
};

#endif //P1_HASHTABLE_H

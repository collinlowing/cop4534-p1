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
#include "StringNode.hpp"

template <class T, class D, class K> class HashTable {
private:
    static int numBuckets;
    std::vector<StringNode*> table;
    int hash(T* node);
public:
    HashTable();
    HashTable(int numBuckets);
    void add(D data, K key);
    void remove(K key);
    T* search(K key);
    ~HashTable();
};

#endif //P1_HASHTABLE_H

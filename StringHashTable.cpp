//
// Created by cel on 8/12/22.
//

#include "StringHashTable.hpp"


StringHashTable::StringHashTable(std::size_t numBuckets) {
    if (numBuckets <= 0) {
        throw std::invalid_argument("number of buckets in hash table must be greater than 0");
    }

    this->numBuckets = numBuckets;

    table = new StringNode[this->numBuckets]();
}

std::size_t StringHashTable::hash(std::string key) {
    return StringHasher::hash(key) % numBuckets;
}

void StringHashTable::add(std::string &data, std::string &key) {
    std::size_t index = StringHashTable::hash(key);
    StringNode *newNode = new StringNode(data, key);

    table[index] = *newNode;
}

bool StringHashTable::remove(std::string key) {
    std::size_t index = StringHashTable::hash(key);

    // check if table is empty
    if (table == nullptr) {
        return false;
    }

    // get node to delete
    StringNode *node = search(key);
    StringNode *temp = node;

    node = nullptr;

    return true;
}

StringNode *StringHashTable::search(std::string key) {
    for (int i = 0; i < numBuckets; i++) {
        if (key == table[i].getKey()) {
            return &table[i];
        }
    }
    return nullptr;
}

StringHashTable::~StringHashTable() {

}
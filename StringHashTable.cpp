//
// Created by cel on 8/12/22.
//

#include "StringHashTable.hpp"


StringHashTable::StringHashTable(std::size_t numBuckets) {
    if(numBuckets <= 0)
    {
        throw std::invalid_argument("number of buckets in hash table must be greater than 0");
    }

    this->numBuckets = numBuckets;

    table.resize(this->numBuckets);
}

std::size_t StringHashTable::hash(std::string key) {
    return std::hash<std::string>{}(key) % numBuckets;
}

void StringHashTable::add(std::string &data, std::string &key) {
    std::size_t index = hash(key);
    StringNode* newNode = new StringNode(data, key);

    table.push_back(newNode);
}

bool StringHashTable::remove(std::string key) {
    std::size_t index = hash(key);

    if(table.empty())
    {
        return false;
    }
    for(int i = 0; i < table.size(); i++)
    {
        if(table.at(i)->getKey() == key)
        {
            delete table.at(i);
            return true;
        }
    }
}

StringNode *StringHashTable::search(std::string key) {
    return nullptr;
}

StringHashTable::~StringHashTable() {

}
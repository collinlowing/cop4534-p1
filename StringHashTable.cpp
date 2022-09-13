//
// Created by cel on 8/12/22.
//

#include "StringHashTable.hpp"


StringHashTable::StringHashTable(std::size_t size) {
    if (size <= 0) {
        throw std::invalid_argument("number of buckets in hash table must be greater than 0");
    }

    TABLE_SIZE = size;

    table = new StringNode*[TABLE_SIZE]();

    for(int i = 0; i < TABLE_SIZE; i++)
    {
        table[i] = nullptr;
    }
}

std::size_t StringHashTable::hash(std::string key) {
    return StringHasher::hash(key) % TABLE_SIZE;
}

void StringHashTable::add(std::string data, std::string key) {
    std::size_t index = StringHashTable::hash(key);
    StringNode* entry = table[index];
    StringNode* previousNode = nullptr;
    StringNode* newNode = new StringNode(data, key);

    // if node at index is empty
    if(entry == nullptr)
    {
        table[index] = newNode;
    }

    // node already exists at index
    else {
        while(entry != nullptr)
        {
            newNode->setPrevious(entry);
            entry = entry->getNext();
        }

        entry = newNode;
    }
}

/*
bool StringHashTable::remove(std::string key) {
    // get hash index
    std::size_t index = hash(key);

    current = &table[index];

    if(current == nullptr)
    {
        // not found
        return false;
    }
    else if(previous == nullptr)
    {
        table[index] = *current->getNext();
    }
    else
    {
        previous->getNext() = current->getNext();
    }

    return true;
}
*/

//TODO: fix search
StringNode *StringHashTable::search(std::string key) {
    // get hash index
    std::size_t index = hash(key);
    bool found = false;
    StringNode * entry = table[index];

    if(entry != nullptr){
        while (entry != nullptr) {
            if(entry->getKey() == key) {
                found = true;
            }
            if(found) {
                return entry;
            }
            entry = entry->getNext();
        }
    }
    if (!found)
    {
        return nullptr;
    }
}

StringHashTable::~StringHashTable() {
    delete[] table;
}
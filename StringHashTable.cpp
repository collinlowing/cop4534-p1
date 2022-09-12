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

void StringHashTable::add(std::string data, std::string key) {
    std::size_t index = StringHashTable::hash(key);
    StringNode *newNode = new StringNode(data, key);
    if (&table[index] == nullptr || table[index].getKey() == "") {
        table[index] = *newNode;
    }
    else {
        current = &table[index];

        while(current != nullptr && current->getKey() != "") {
            previous = current;
            current = current->getNext();
        }

        current = newNode;
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

    current = &table[index];

    std::cout << current->getKey() << std::endl;
    std::cout << current->getData() << std::endl;

    while(current->getNext() != nullptr && current->getKey() != key) {
        current = current->getNext();
        if(current->getKey() == key)
        {
            return  current;
        }
    }
    return nullptr;
}

StringHashTable::~StringHashTable() {
//    for (int i = 0; i < numBuckets; i++)
//    {
//        current = &table[i];
//
//        if(current == nullptr)
//        {
//            // bucket is empty
//            continue;
//        }
//
//        while (current->getNext() != nullptr)
//        {
//            StringNode * temp = current;
//
//            current = current->getNext();
//
//            delete temp;
//        }
//
//        delete current;
//    }
//    delete [] table;
}
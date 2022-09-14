/***************************************************************
  Student Name: Collin Lowing
  File Name: StringHashTable.cpp
  Project 1

  Externally chained hashtable that stores two strings in a StringNode
***************************************************************/

#include "StringHashTable.hpp"

// initializes hashtable max size
StringHashTable::StringHashTable(const std::size_t size) {
    if (size <= 0) {
        throw std::invalid_argument("number of buckets in hash table must be greater than 0");
    }

    TABLE_SIZE = size;

    table = new StringNode *[TABLE_SIZE]();

    // initializes all pointers to nullptr
    for (std::size_t i = 0; i < TABLE_SIZE; i++) {
        table[i] = nullptr;
    }
}

// gets hash value adjusted for TABLE_SIZE
std::size_t StringHashTable::hash(std::string key) {
    return StringHasher::hash(key) % TABLE_SIZE;
}

// adds a set of two strings to table
void StringHashTable::add(std::string data, std::string key) {
    std::size_t index = StringHashTable::hash(key); // get hash index
    StringNode *current = table[index];   // creates a referential pointer at hash index
    StringNode *newNode = new StringNode(data, key);    // initializes new node to add

    // if node at index is empty
    if (current == nullptr) {
        table[index] = newNode;
    }

    // node already exists at index
    else {
        while (current != nullptr) {
            newNode->setPrevious(current);
            current = current->getNext();
        }

        current = newNode;
    }
}

// gets a node from table using the key value
StringNode *StringHashTable::search(std::string key) {
    std::size_t index = hash(key);  // get hash index
    bool found = false; // flag for found key
    StringNode *current = table[index]; // creates a referential pointer at hash index

    // if index is not empty
    if (current != nullptr) {
        // iterate through chain until reached the end
        while (current != nullptr) {
            // found key
            if (current->getKey() == key) {
                found = true;
            }
            if (found) {
                return current;
            }
            // go to next node in chain
            current = current->getNext();
        }
    }
    return nullptr; // not found
}

// deletes table
StringHashTable::~StringHashTable() {
    delete[] table;
}
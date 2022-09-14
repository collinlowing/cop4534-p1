/***************************************************************
  Student Name: Collin Lowing
  File Name: StringNode.cpp
  Project 1

  Stores string data and key for externally chained hashtable
***************************************************************/

#include "StringNode.hpp"

// initialize default values
StringNode::StringNode() {
    this->data = "";
    this->key = "";
}

// initialize assigned values
StringNode::StringNode(std::string data, std::string key) {
    this->data = data;
    this->key = key;
}

/*
 * Setters and Getters
 */
std::string StringNode::getData() {
    return data;
}

std::string StringNode::getKey() {
    return key;
}

StringNode *StringNode::getNext() {
    return next;
}

void StringNode::setNext(StringNode *next) {
    this->next = next;
}

void StringNode::setPrevious(StringNode *previous) {
    this->previous = previous;
}

StringNode *StringNode::getPrevious() {
    return previous;
}

// delete memory
StringNode::~StringNode() {
    delete next;
    delete previous;
}


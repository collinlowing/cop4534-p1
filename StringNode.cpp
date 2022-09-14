//
// Created by cel on 7/12/22.
//

#include "StringNode.hpp"


StringNode::StringNode() {
    this->data = "";
    this->key = "";
}

StringNode::StringNode(std::string data, std::string key) {
    this->data = data;
    this->key = key;
}

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

StringNode::~StringNode() {
    delete next;
    delete previous;
}


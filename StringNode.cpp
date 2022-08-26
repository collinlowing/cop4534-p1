//
// Created by cel on 7/12/22.
//

#include "StringNode.hpp"


StringNode::StringNode() {
    data = "";
    key = "";
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

std::size_t StringNode::hash() {
    return std::hash<std::string>{}(key);
}
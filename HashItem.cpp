//
// Created by cel on 6/13/22.
//

#include <string>
#include "HashItem.hpp"

HashItem::HashItem() {
    this->userID = "username";
    this->password = "password";
}

HashItem::HashItem(std::string userID, std::string password) {
    this->userID = userID;
    this->password = password;
}

std::string HashItem::getPassword() {
    return password;
}

void HashItem::setPassword(std::string password) {
    this->password = password;
}

std::string HashItem::getUserID() {
    return userID;
}

void HashItem::setUserID(std::string userID) {
    this->userID = userID;
}

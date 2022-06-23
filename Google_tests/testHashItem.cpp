//
// Created by cel on 6/23/22.
//

#include "gtest/gtest.h"
#include "../HashItem.hpp"

// get userID
TEST(HashItemTests, getUserID) {
    std::string expectedUserID = "collin";
    HashItem hi(expectedUserID, "password");
    std::string userID = hi.getUserID();
    EXPECT_EQ(userID, expectedUserID);
}

// get password
TEST(HashItemTests, getPassword) {
    std::string expectedPassword = "testtest";
    HashItem hi("username", expectedPassword);
    std::string password = hi.getPassword();
    EXPECT_EQ(password, expectedPassword);
}

// set userID
TEST(HashItemTests, setUserID) {
    std::string expectedUserID = "collin";
    HashItem hi;
    std::string userID = hi.getUserID();
    EXPECT_NE(expectedUserID, userID);
    hi.setUserID(expectedUserID);
    userID = hi.getUserID();
    EXPECT_EQ(userID, expectedUserID);
}

// set password
TEST(HashItemTests, setPassword) {
    std::string expectedPassword = "testtest";
    HashItem hi;
    std::string password = hi.getPassword();
    EXPECT_NE(password, expectedPassword);
    hi.setPassword(expectedPassword);
    password = hi.getPassword();
    EXPECT_EQ(password, expectedPassword);
}
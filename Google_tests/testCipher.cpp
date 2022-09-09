//
// Created by cel on 6/13/22.
//

#include "gtest/gtest.h"
#include "../VigenereCipher.hpp"

// Test getting key parameterized constructor
TEST(CipherTests, paramKey) {
    // assign key string
    std::string key = "test";
    // pass key into constructor
    VigenereCipher c1(key);
    // get key
    std::string testStr = c1.getKey();
    // key and test string must be equal
    EXPECT_EQ(key, testStr);
}

// Test getting key default constructor
TEST(CipherTests, defaultKey) {
    // assign key string
    std::string key = "jones";
    // pass key into constructor
    VigenereCipher c2;
    // get key
    std::string testStr = c2.getKey();
    // key and test string must be equal
    EXPECT_EQ(key, testStr);
}

// Test getting key default constructor
TEST(CipherTests, setKey) {
    // assign key string
    std::string key = "test";
    // pass key into constructor
    VigenereCipher c3;
    // set key
    c3.setKey(key);
    // get key
    std::string testStr = c3.getKey();
    // key and test string must be equal
    EXPECT_EQ(key, testStr);
}

// Test resizing key
TEST(CipherTests, resizeKey) {
    // assign key string
    std::string key = "encrypt";
    // pass key into constructor
    VigenereCipher c4(key);
    // assign message string to encrypt
    std::string message = "thisisamessage";
    // resize key to fit message
    std::string resizedKey = c4.resize(key, message);
    // assign expected resized key
    std::string expectedKey = "encryptencrypt";
    // resized key and expected key must match
    EXPECT_EQ(resizedKey, expectedKey);
}

// Test encrypting message
TEST(CipherTests, ecryptMessage) {
    // assign key string
    std::string key = "encrypt";
    // pass key into constructor
    VigenereCipher c5(key);
    // assign message string to encrypt
    std::string message = "thisisamessage";
    // encrypt message
    std::string encryptedMsg = c5.encrypt(message);
    // assign expected encrypted string
    std::string expectedStr = "xukjghtqrujyvx";
    // encrypted message and expected string must match
    EXPECT_EQ(encryptedMsg, expectedStr);
}

// Test decrypting message
TEST(CipherTests, decryptMessage) {
    // assign key string
    std::string key = "encrypt";
    // pass key into constructor
    VigenereCipher c6(key);
    // assign encrypted message
    std::string encryptedMsg = "xukjghtqrujyvx";
    // decrypt message
    std::string decryptedMsg = c6.decrypt(key, encryptedMsg);
    // assign expected decrypted string
    std::string expectedStr = "thisisamessage";
    // decrypted message and expected string must match
    EXPECT_EQ(decryptedMsg, expectedStr);
}
/***************************************************************
  Student Name: Collin Lowing
  File Name: VigenereCipher.cpp
  Project 1

  Encrypts a string using a key with the Vigenere Cipher.
***************************************************************/

#include "VigenereCipher.hpp"

// default key
VigenereCipher::VigenereCipher() {
    this->key = "jones";
}

// custom key
VigenereCipher::VigenereCipher(std::string key) {
    this->key = key;
}

/*
 * Setter and Getter
 */
std::string VigenereCipher::getKey() {
    return this->key;
}

void VigenereCipher::setKey(std::string key) {
    this->key = key;
}

// use Vigenere Cipher to encrypt message
std::string VigenereCipher::encrypt(std::string message) {
    // resize encryption key to be same length as message
    std::string resizedKey = resize(key, message);

    //initialize encrypted message
    std::string encryptedMsg = "";

    // iterate through message
    for (std::size_t i = 0, j = 0; i < message.size(); i++) {
        // get character from message
        char c = message[i];

        // translate character based on key
        encryptedMsg += (c + resizedKey[j] - 2 * 'a') % 26 + 'a'; //added 'a' to convert to ASCII alphabet
        j++;
    }

    return encryptedMsg;
}

// resize key to match message length
std::string VigenereCipher::resize(std::string key, std::string message) {
    std::size_t msgLength = message.length();
    int keyLength = key.length();
    std::string resizedKey = "";

    int i = 0;
    while(true) {
        // restart key pattern
        if (keyLength == i)
            i = 0;
        // when key is the same length as message
        if (resizedKey.length() == msgLength)
            break;
        // add character from key to new length key
        resizedKey.append(1, key[i]);

        i++;
    }
    return resizedKey;
}

std::string VigenereCipher::decrypt(const std::string key, std::string message) {
    // resize encryption key to be same length as message
    std::string resizedKey = resize(key, message);

    //initialize decrypted message
    std::string decryptedMsg = "";

    // iterate through message
    for (std::size_t i = 0, j = 0; i < message.size(); i++) {
        // get character from message
        char c = message[i];

        // translate character based on key
        decryptedMsg += (c - resizedKey[j] + 26) % 26 + 'a'; //added 'a' to convert to ASCII alphabet
        j++;
    }

    return decryptedMsg;
}

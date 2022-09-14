//
// Created by cel on 6/13/22.
//

#include "VigenereCipher.hpp"

VigenereCipher::VigenereCipher() {
    this->key = "jones";
}

VigenereCipher::VigenereCipher(std::string key) {
    this->key = key;
}

std::string VigenereCipher::getKey() {
    return this->key;
}

void VigenereCipher::setKey(std::string key) {
    this->key = key;
}

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

std::string VigenereCipher::resize(std::string key, std::string message) {
    std::size_t msgLength = message.length();
    //std::cout << msgLength << std::endl;
    int keyLength = key.length();
    //std::cout << keyLength << std::endl;

    std::string resizedKey = "";

    for (int i = 0;; i++) {
        if (keyLength == i)
            i = 0;
        if (resizedKey.length() == msgLength)
            break;
        resizedKey.append(1, key[i]);
    }
    //std::cout << resizedKey << std::endl;
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

/***************************************************************
  Student Name: Collin Lowing
  File Name: VigenereCipher.hpp
  Project 1

  Encrypts a string using a key with the Vigenere Cipher.
***************************************************************/

#ifndef COP4534_P1_VIGENERECIPHER_HPP
#define COP4534_P1_VIGENERECIPHER_HPP


#include <iostream>
#include <string>

class VigenereCipher {
private:
    std::string key;
public:
    VigenereCipher();

    VigenereCipher(std::string key);

    std::string getKey();

    std::string encrypt(std::string message);

    std::string resize(std::string key, std::string message);

    std::string decrypt(std::string key, std::string message);

    void setKey(std::string key);
};


#endif //COP4534_P1_VIGENERECIPHER_HPP

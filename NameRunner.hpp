//
// Created by cel on 9/11/22.
//

#ifndef COP4534_P1_NAMERUNNER_HPP
#define COP4534_P1_NAMERUNNER_HPP

#include "Parser.hpp"
#include "StringHashTable.hpp"
#include "PasswordGenerator.hpp"
#include "VigenereCipher.hpp"

class NameRunner {
private:
    const std::size_t HASH_SIZE = 100;
    StringHashTable* hashTable;
    std::string namesFileName = "names.txt";
    std::string rawFileName = "rawdata.txt";
    std::string encryptedFileName = "encrypteddata.txt";
    std::size_t passwordLength = 9;
public:
    void start();
    void runTests();
    ~NameRunner();
};


#endif //COP4534_P1_NAMERUNNER_HPP

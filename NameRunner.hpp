/***************************************************************
  Student Name: Collin Lowing
  File Name: NameRunner.hpp
  Project 1

  Runs the program operations using methods from other classes.
***************************************************************/

#ifndef COP4534_P1_NAMERUNNER_HPP
#define COP4534_P1_NAMERUNNER_HPP

#include "Parser.hpp"
#include "StringHashTable.hpp"
#include "PasswordGenerator.hpp"
#include "VigenereCipher.hpp"

class NameRunner {
private:
    const std::size_t HASH_SIZE = 100;
    StringHashTable *hashTable;
    std::string namesFileName = "names.txt";
    std::string rawFileName = "rawdata.txt";
    std::string encryptedFileName = "encrypteddata.txt";
    std::size_t passwordLength = 9;
public:
    void start();   // runs code operations

    void runTests();    // runs tests

    ~NameRunner();  // cleans up memory
};


#endif //COP4534_P1_NAMERUNNER_HPP

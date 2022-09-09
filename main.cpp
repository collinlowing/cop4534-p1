#include <iostream>

#include "Parser.hpp"
#include "StringHashTable.hpp"
#include "PasswordGenerator.hpp"
#include "VigenereCipher.hpp"

void runTests();

int main() {
    const std::size_t HASH_SIZE = 44000;
    StringHashTable hashTable(HASH_SIZE);
    std::string namesFileName = "names.txt";
    std::string rawFileName = "rawdata.txt";
    std::string encryptedFileName = "encrypteddata.txt";
    std::size_t passwordLength = 9;
    std::vector<std::string> names = Parser::readNames(namesFileName);
    std::vector<std::string> output;
    int multiplier = 1;
    for (auto name : names) {
        int randomSeed = time(0) * multiplier;

        std::string password = PasswordGenerator::generatePassword(passwordLength, randomSeed);
        multiplier++;
        output.push_back(name);
        output.push_back(password);
    }

    // write to rawdata.txt
    Parser::outputData(output, rawFileName);
    output.clear();

    // get data from rawdata.txt
    std::vector<std::string> data = Parser::readData(rawFileName);

    // create encrypted passwords
    for(int i = 0; i < data.size(); i++)
    {
        std::string name;
        std::string password;

        // name is first
        if(Parser::even(i))
        {
            name = data.at(i);
            output.push_back(name);
        }
        // password is second
        else
        {
            VigenereCipher cipher;
            password = cipher.encrypt(data.at(i));
            output.push_back(password);
        }
        // load into hashtable
        hashTable.add(password, name);
    }

    // write to encrypteddata.txt
    Parser::outputData(output, encryptedFileName);

    runTests();

    return 0;
}

void runTests() {

}

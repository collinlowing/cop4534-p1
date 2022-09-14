/***************************************************************
  Student Name: Collin Lowing
  File Name: NameRunner.cpp
  Project 1

  Runs the program operations using methods from other classes.
***************************************************************/

#include "NameRunner.hpp"

void NameRunner::start() {
    // initialize table, name list, list for outputting to file, multiplier for seed
    hashTable = new StringHashTable(NameRunner::HASH_SIZE);
    std::vector<std::string> names = Parser::readNames(namesFileName);
    std::vector<std::string> output;
    int multiplier = 1;

    // generate random passwords
    for (auto name: names) {
        int randomSeed = time(0) * multiplier;

        std::string password = PasswordGenerator::generatePassword(passwordLength, randomSeed);
        multiplier++;

        // add name and password to output in order
        output.push_back(name);
        output.push_back(password);
    }

    // write to rawdata.txt
    Parser::outputData(output, rawFileName);
    output.clear();

    // get data from rawdata.txt
    std::vector<std::string> data = Parser::readData(rawFileName);

    // create encrypted passwords
    for (std::size_t i = 0; i < data.size(); i += 2) {
        // declare variables
        std::string name;
        std::string password;
        VigenereCipher cipher;

        // initialize name and add it to the new output, unchanged.
        name = data.at(i);
        output.push_back(name);

        // encrypt password and add to output
        password = cipher.encrypt(data.at(i + 1));
        output.push_back(password);

        // load into hashtable
        hashTable->add(password, name);
    }

    // write to encrypteddata.txt
    Parser::outputData(output, encryptedFileName);
}

void NameRunner::runTests() {
    // initialize variables for testing 5 entries into hashtable
    const size_t numItems = 5;
    std::string userIDs[numItems] = {};
    std::string passwords[numItems] = {};
    bool matches[numItems];

    // get data from rawdata.txt
    std::vector<std::string> fileData = Parser::readData(encryptedFileName);

    // grabbing userID and password for line 1,3,5,7,9
    int j = 0;
    for (int i = 0; i <= 16; i += 4) {
        userIDs[j] = fileData.at(i);
        passwords[j] = fileData.at(i + 1);

        j++;
    }

    // check if they match with hashtable
    for (std::size_t i = 0; i < numItems; i++) {
        StringNode *node = hashTable->search(userIDs[i]);
        if (node->getData() == passwords[i])
            matches[i] = true;
        else
            matches[i] = false;
    }

    std::cout << "Legal:" << std::endl;
    std::cout << "UserID\tPassword\tResult" << std::endl;

    // print out all the data
    for (std::size_t i = 0; i < 5; i++) {
        // checks if the passwords were previously matched
        if (matches[i])
            std::cout << userIDs[i] << "\t" << passwords[i] << "\t" << "match" << std::endl;
        else
            std::cout << userIDs[i] << "\t" << passwords[i] << "\t" << "no match" << std::endl;
    }

    // add char 'a' to all passwords
    for (auto &password: passwords) {
        password += 'a';
    }

    // check if they match with hashtable
    for (std::size_t i = 0; i < numItems; i++) {
        StringNode *node = hashTable->search(userIDs[i]);
        if (node->getData() == passwords[i])
            matches[i] = true;
        else
            matches[i] = false;
    }

    std::cout << "Illegal:" << std::endl;
    std::cout << "UserID\tPassword\tResult" << std::endl;

    // print out all the data
    for (int i = 0; i < 5; i++) {
        // checks if the passwords were previously matched
        if (matches[i])
            std::cout << userIDs[i] << "\t" << passwords[i] << "\t" << "match" << std::endl;
        else
            std::cout << userIDs[i] << "\t" << passwords[i] << "\t" << "no match" << std::endl;
    }
}

NameRunner::~NameRunner() {
    delete hashTable;
}

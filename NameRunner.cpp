//
// Created by cel on 9/11/22.
//

#include "NameRunner.hpp"

void NameRunner::start() {
    hashTable = new StringHashTable(NameRunner::HASH_SIZE);
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
    for(int i = 0; i < data.size(); i+=2)
    {
        std::string name;
        std::string password;
        VigenereCipher cipher;

        name = data.at(i);
        output.push_back(name);

        password = cipher.encrypt(data.at(i+1));
        output.push_back(password);

        // load into hashtable
        hashTable->add(password, name);
    }

    // write to encrypteddata.txt
    Parser::outputData(output, encryptedFileName);
}

void NameRunner::runTests() {
    const size_t numItems = 5;
    std::string userIDs[numItems] = {};
    std::string passwords[numItems] = {};
    bool matches[numItems];

    // get data from rawdata.txt
    std::vector<std::string> fileData = Parser::readData(encryptedFileName);

    // grabbing userID and password for line 1,3,5,7,9
    int j = 0;
    for(int i = 0; i <= 16; i+=4)
    {
        userIDs[j] = fileData.at(i);
        passwords[j] = fileData.at(i+1);

        j++;
    }

    // check if they match with hashtable
    for (int i = 0; i < numItems; i++)
    {
        StringNode * node = hashTable->search(userIDs[i]);
        if(node->getData() == passwords[i])
            matches[i] = true;
        else
            matches[i] = false;
    }

    std::cout << "Legal:" << std::endl;
    std::cout << "UserID\tPassword\tResult" << std::endl;

    // print out all the data
    for (int i = 0; i < 5; i++)
    {
        if(matches[i])
            std::cout << userIDs[i] << "\t" << passwords[i] << "\t" << "match" << std::endl;
        else
            std::cout << userIDs[i] << "\t" << passwords[i] << "\t" << "no match" << std::endl;
    }

    // add char 'a' to all passwords
    for(auto & password : passwords)
    {
        password += 'a';
    }

    // check if they match with hashtable
    for (int i = 0; i < numItems; i++)
    {
        StringNode * node = hashTable->search(userIDs[i]);
        if(node->getData() == passwords[i])
            matches[i] = true;
        else
            matches[i] = false;
    }

    std::cout << "Illegal:" << std::endl;
    std::cout << "UserID\tPassword\tResult" << std::endl;

    for (int i = 0; i < 5; i++)
    {
        if(matches[i])
            std::cout << userIDs[i] << "\t" << passwords[i] << "\t" << "match" << std::endl;
        else
            std::cout << userIDs[i] << "\t" << passwords[i] << "\t" << "no match" << std::endl;
    }
}

NameRunner::~NameRunner() {
    //delete hashTable;
}

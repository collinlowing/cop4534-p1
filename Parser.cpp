/***************************************************************
  Student Name: Collin Lowing
  File Name: Parser.cpp
  Project 1

  Handles file I/O operations
***************************************************************/

#include "Parser.hpp"

// read names from names.txt or another filename
std::vector<std::string> Parser::readNames(std::string fileName) {
    // initialize file input stream, name and vector for names
    std::ifstream inputFileStream(fileName);
    std::string name = "";
    std::vector<std::string> names;

    // check if file was successfully opened
    if (!inputFileStream) {
        std::cout << fileName << " could not be opened" << std::endl;
    }

    // iterates though file until EOF is reached
    while (inputFileStream >> name) {

        // adds name to names vector
        names.push_back(name);

        // ignores everything else after first "word"
        inputFileStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    inputFileStream.close();

    return names;
}

// outputs rawdata and encrypted data
bool Parser::outputData(std::vector<std::string> data, std::string fileName) {

    // initialize output file stream
    std::ofstream outputFileStream(fileName);

    // checks if file is successfully opened/created
    if (!outputFileStream) {
        std::cout << fileName << " could not be opened." << std::endl;

        return false;
    }

    // checks if data is valid for outputting to a file. matching names and passwords
    if (data.size() <= 0 || !even(data.size())) {
        std::cout << "data is not valid for writing to file" << std::endl;
        return false;
    }

    // outputting data to file with tab between name and password
    std::size_t counter = 0;
    for (auto item: data) {
        if (even(counter))
            outputFileStream << item << "\t";
        else
            outputFileStream << item << std::endl;

        counter++;
    }

    outputFileStream.close();

    return true; //success
}

// checks if a number is even
bool Parser::even(std::size_t number) {
    return (number % 2 == 0);
}

// read data that was previously written.
std::vector<std::string> Parser::readData(std::string fileName) {

    // initializes input file stream and data, and vector
    std::ifstream inputFileStream(fileName);
    std::string data = "";
    std::vector<std::string> dataVector;

    // checks if file was successfully opened
    if (!inputFileStream) {
        std::cout << fileName << " could not be opened" << std::endl;
    }

    // iterates through file until EOF is reached, adds data to vector
    while (inputFileStream >> data) {
        dataVector.push_back(data);
    }

    // close file
    inputFileStream.close();

    return dataVector;
}

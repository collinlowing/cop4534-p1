//
// Created by cel on 6/13/22.
//

#include "Parser.hpp"

std::vector<std::string> Parser::readNames(std::string fileName) {
    std::ifstream inputFileStream(fileName);
    std::string name = "";
    std::vector<std::string> names;


    if (!inputFileStream) {
        std::cout << fileName << " could not be opened" << std::endl;
    }

    while (inputFileStream >> name) {

        names.push_back(name);

        inputFileStream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    inputFileStream.close();
    return names;
}

bool Parser::outputData(std::vector<std::string> data, std::string fileName) {

    std::ofstream outputFileStream(fileName);

    if (!outputFileStream) {
        std::cout << fileName << " could not be opened." << std::endl;

        return false;
    }

    if (data.size() <= 0 || !even(data.size())) {
        std::cout << "data is not valid for writing to file" << std::endl;
        return false;
    }

    std::size_t counter = 0;
    for (auto item: data) {
        if (even(counter))
            outputFileStream << item << "\t" << std::endl;
        else
            outputFileStream << item << std::endl;
    }

    outputFileStream.close();

    return true;
}

bool Parser::even(std::size_t number) {
    return (number % 2 == 0);
}

std::vector<std::string> Parser::readData(std::string fileName) {
    std::ifstream inputFileStream(fileName);
    std::string data = "";
    std::vector<std::string> dataVector;


    if (!inputFileStream) {
        std::cout << fileName << " could not be opened" << std::endl;
    }

    while (inputFileStream >> data) {
        dataVector.push_back(data);
    }

    std::cout << dataVector.size() << std::endl;

    inputFileStream.close();
    return dataVector;
}

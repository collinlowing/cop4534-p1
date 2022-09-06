//
// Created by cel on 6/13/22.
//

#ifndef P1_PARSER_H
#define P1_PARSER_H


#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>

class Parser {

public:
    static std::vector<std::string> readNames(std::string fileName);

    static bool outputData(std::vector<std::string> data, std::string fileName);

    static bool even(std::size_t number);

    static std::vector<std::string> readData(std::string fileName);
};


#endif //P1_PARSER_H

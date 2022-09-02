//
// Created by cel on 6/13/22.
//

#ifndef P1_PARSER_H
#define P1_PARSER_H


#include <vector>
#include <string>

class Parser {

public:
    std::vector<std::string> readNames(std::string fileName);

    bool outputData(std::vector<std::string> data, std::string fileName);

    std::vector<std::string> readData(std::string fileName);
};


#endif //P1_PARSER_H

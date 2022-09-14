/***************************************************************
  Student Name: Collin Lowing
  File Name: Parser.hpp
  Project 1

  Handles file I/O operations
***************************************************************/

#ifndef P1_PARSER_H
#define P1_PARSER_H


#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <limits>

class Parser {

public:
    static std::vector<std::string> readNames(std::string fileName);    // read names from names.txt or another filename

    static bool outputData(std::vector<std::string> data, std::string fileName);    // outputs rawdata and encrypted data

    static bool even(std::size_t number);   // checks if a number is even

    static std::vector<std::string> readData(std::string fileName); // read data that was previously written.
};


#endif //P1_PARSER_H

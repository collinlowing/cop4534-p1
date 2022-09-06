#include <iostream>

#include "Parser.hpp"

int main() {
    std::vector<std::string> data;
    data.emplace_back("collin\tpassword");
    data.emplace_back("john\ttest");
    Parser::outputData(data, "rawdata.txt");

    return 0;
}

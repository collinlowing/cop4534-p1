#include <iostream>

#include "Parser.hpp"
#include "StringHashTable.hpp"

int main() {
//    std::vector<std::string> vect;
//    vect.emplace_back("collin\tpassword");
//    vect.emplace_back("john\ttest");
//    Parser::outputData(vect, "rawdata.txt");

    std::size_t numBuckets = 11;
    StringHashTable hashTable(numBuckets);
    std::string data = "name";
    std::string key = "password";
    StringNode *searchedNode1 = nullptr;
    StringNode *searchedNode2 = nullptr;

    hashTable.add(data, key);


    searchedNode1 = hashTable.search(key);

    if(searchedNode1 != nullptr)
        std::cout << searchedNode1->getData() << std::endl;

    //TODO: Not actually removing the node
    hashTable.remove(key);
    searchedNode2 = hashTable.search(key);

    if(searchedNode2 != nullptr)
        std::cout << searchedNode2->getData() << std::endl;

    return 0;
}

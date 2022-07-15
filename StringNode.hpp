//
// Created by cel on 7/12/22.
//

#ifndef COP4534_P1_STRINGNODE_HPP
#define COP4534_P1_STRINGNODE_HPP


#include <string>
#include "HashNode.hpp"

class StringNode: public HashNode {
private:
    std::string data;
    std::string key;
    StringNode* next;
public:
    StringNode();
    StringNode(std::string data, std::string key);  // parameters for initial values
    std::string getData();
    std::string getKey();
    StringNode* getNext();
    void setNext(StringNode* next);
    std::size_t hash() override;    // override abstract hash() function
};


#endif //COP4534_P1_STRINGNODE_HPP

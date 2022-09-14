//
// Created by cel on 7/12/22.
//

#ifndef COP4534_P1_STRINGNODE_HPP
#define COP4534_P1_STRINGNODE_HPP


#include <string>

class StringNode {
private:
    std::string data;
    std::string key;
    StringNode *next = nullptr;
    StringNode *previous = nullptr;
public:
    StringNode();

    StringNode(std::string data, std::string key);  // parameters for initial values
    std::string getData();

    std::string getKey();

    StringNode *getNext();

    StringNode *getPrevious();

    void setNext(StringNode *next);

    void setPrevious(StringNode *pNode);

    ~StringNode();
};


#endif //COP4534_P1_STRINGNODE_HPP

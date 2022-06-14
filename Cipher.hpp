//
// Created by cel on 6/13/22.
//

#ifndef COP4534_P1_CIPHER_HPP
#define COP4534_P1_CIPHER_HPP


#include <iostream>
#include <string>

class Cipher {
private:
    char* message;
    const char* key = "jones";
    char* resized_key;
public:
    const char* getKey();
};


#endif //COP4534_P1_CIPHER_HPP

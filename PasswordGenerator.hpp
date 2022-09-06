//
// Created by cel on 9/6/22.
//

#ifndef COP4534_P1_PASSWORDGENERATOR_HPP
#define COP4534_P1_PASSWORDGENERATOR_HPP

#include <string>
#include <stdlib.h>

class PasswordGenerator {
public:
    static std::string generatePassword(std::size_t length, int seed);
};


#endif //COP4534_P1_PASSWORDGENERATOR_HPP

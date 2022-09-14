/***************************************************************
  Student Name: Collin Lowing
  File Name: PasswordGenerator.hpp
  Project 1

  Generates a random password with a provided seed value.
***************************************************************/

#ifndef COP4534_P1_PASSWORDGENERATOR_HPP
#define COP4534_P1_PASSWORDGENERATOR_HPP

#include <string>
#include <stdlib.h>

class PasswordGenerator {
public:
    static std::string generatePassword(std::size_t length, int seed);
};


#endif //COP4534_P1_PASSWORDGENERATOR_HPP

/***************************************************************
  Student Name: Collin Lowing
  File Name: StringHasher.hpp
  Project 1

  Implements a hashing function for a string value.
***************************************************************/

#ifndef COP4534_P1_STRINGHASHER_HPP
#define COP4534_P1_STRINGHASHER_HPP

#include <iostream>

class StringHasher {
public:
    // hashes string into an unsigned long int
    static std::size_t hash(std::string key) {
        std::size_t total = 0;
        for (std::size_t i = 0; i < key.length(); i++) {
            char c = key[i];
            total += c;
        }

        return total;
    }
};

#endif //COP4534_P1_STRINGHASHER_HPP

//
// Created by cel on 8/29/22.
//

#ifndef COP4534_P1_STRINGHASHER_HPP
#define COP4534_P1_STRINGHASHER_HPP

#include <iostream>

class StringHasher {
public:
    static std::size_t hash(std::string key) {
        std::size_t total = 1;
        for (int i = 0; i < key.length(); i++) {
            char c = key[i];
            total *= c;
        }

        return total;
    }
};

#endif //COP4534_P1_STRINGHASHER_HPP

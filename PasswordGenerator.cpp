//
// Created by cel on 9/6/22.
//

#include "PasswordGenerator.hpp"

std::string PasswordGenerator::generatePassword(std::size_t length, int seed) {
    std::string password = "";
    std::srand(seed);    // initialize the random number generator with a seed
    for (std::size_t i = 0; i < length; i++) {
        int randomNum = rand() % 26;   // generate a random number between 0 and 26
        password += 'a' + randomNum;    // convert random number to lowercase character
    }

    return password;
}
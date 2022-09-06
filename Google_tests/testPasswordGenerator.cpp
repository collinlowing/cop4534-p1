//
// Created by cel on 9/6/22.
//

#include "gtest/gtest.h"
#include "../PasswordGenerator.hpp"

// get names from file names.txt
TEST(GeneratorTest, getPassword) {
    int seed = 1;
    std::size_t length = 9;
    std::string expectedPassword = "nwlrbbmqb";

    std::string password1 = PasswordGenerator::generatePassword(length, seed);
    std::string password2 = PasswordGenerator::generatePassword(length, seed * time(0));


    EXPECT_EQ(password1.size(), length);
    EXPECT_EQ(password2.size(), length);

    EXPECT_EQ(password1, expectedPassword);
    EXPECT_NE(password2, expectedPassword);
}
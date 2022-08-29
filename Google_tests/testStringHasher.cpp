//
// Created by cel on 8/10/22.
//
#include "gtest/gtest.h"
#include "../StringHasher.hpp"

// make hash key
TEST(StringHasherTests, hash) {
std::size_t expectedResult = 1746176491;
std::string key = "password";
std::size_t hash = StringHasher::hash(key);
EXPECT_EQ(hash, expectedResult);
}
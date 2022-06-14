//
// Created by cel on 6/13/22.
//

#include "gtest/gtest.h"
#include "../Cipher.hpp"

TEST(CipherTest, KeyMatch) {
    Cipher c1;
    const char* expectedKey = "jones";
    const char* testKey = c1.getKey();
    EXPECT_EQ(expectedKey, testKey);
}
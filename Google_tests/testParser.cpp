//
// Created by cel on 9/2/22.
//

#include "gtest/gtest.h"
#include "../Parser.hpp"

// get names from file names.txt
TEST(ParserTests, getNames) {
    Parser p;
    std::vector<std::string> names = p.readNames("names.test");
    std::string expectedName1 = "collin";
    std::string expectedName2 = "john";
}

// output raw data for username and passwords.
TEST(ParserTests, outputUsernamePassword)
{
    Parser p;
    std::vector<std::string> data;
    data.push_back("collin\tpassword");
    data.push_back("john\ttest");
    bool success = p.outputData(data, "rawdata.test");
    ASSERT_TRUE(success);
}

// get username and password from output file.
TEST(ParserTests, getUsernamePassword) {
    Parser p;
    std::vector<std::string> data = p.readData("rawdata.test");
    std::string expectedData1 = "collin\tpassword";
    std::string expectedData2 = "john\ttest";

    EXPECT_EQ(data.at(0), expectedData1);
    EXPECT_EQ(data.at(1), expectedData2);
}
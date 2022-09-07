//
// Created by cel on 9/2/22.
//

#include "gtest/gtest.h"
#include "../Parser.hpp"

// get names from file names.txt
TEST(ParserTests, getNames) {
    std::vector<std::string> names = Parser::readNames("../names.test");
    std::string expectedName1 = "COLLIN";
    std::string expectedName2 = "JOHN";

    EXPECT_EQ(names.at(0), expectedName1);
    EXPECT_EQ(names.at(1), expectedName2);
}

// output raw data for username and passwords.
TEST(ParserTests, outputUsernamePassword) {
    std::vector<std::string> data;
    data.emplace_back("collin\tpassword");
    data.emplace_back("john\ttest");
    bool success = Parser::outputData(data, "rawdata.test");
    ASSERT_TRUE(success);
}

// invalid data set being denied
TEST(ParserTests, invalidData) {
    std::vector<std::string> data;
    data.emplace_back("collin\tpassword");
    data.emplace_back("john\ttest");
    data.emplace_back("adam/tapple");
    bool failure = Parser::outputData(data, "rawdata.test");
    ASSERT_FALSE(failure);
}

// get username and password from output file.
TEST(ParserTests, getUsernamePassword) {

    std::vector<std::string> inputData;
    inputData.emplace_back("collin\tpassword");
    inputData.emplace_back("john\ttest");
    Parser::outputData(inputData, "rawdata.test");

    std::vector<std::string> outputData = Parser::readData("rawdata.test");
    std::string expectedData1 = "collin";
    std::string expectedData2 = "password";
    std::string expectedData3 = "john";
    std::string expectedData4 = "test";

    EXPECT_EQ(outputData.at(0), expectedData1);
    EXPECT_EQ(outputData.at(1), expectedData2);
    EXPECT_EQ(outputData.at(2), expectedData3);
    EXPECT_EQ(outputData.at(3), expectedData4);
}
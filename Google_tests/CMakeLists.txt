# 'Google_test' is the subproject name
project(Google_tests)

# 'lib' is the folder with Google Test sources
add_subdirectory(googletest)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})


# 'Google_Tests_run' is the target name
# 'test1.cpp tests2.cpp' are source files with tests
add_executable(Google_Tests_run ../VigenereCipher.cpp ../VigenereCipher.hpp ../StringNode.cpp ../StringNode.hpp ../StringHashTable.cpp ../StringHashTable.hpp ../Parser.hpp ../Parser.cpp ../PasswordGenerator.cpp ../PasswordGenerator.hpp
        testCipher.cpp testHashTable.cpp testStringNode.cpp testStringHasher.cpp testParser.cpp testPasswordGenerator.cpp)
target_link_libraries(Google_Tests_run gtest gtest_main gmock gmock_main)
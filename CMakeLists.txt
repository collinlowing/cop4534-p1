cmake_minimum_required(VERSION 3.23)
project(cop4534_p1)

set(CMAKE_CXX_STANDARD 14)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/names.test
        DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

add_executable(cop4534_p1 main.cpp Cipher.cpp Cipher.hpp StringHashTable.hpp StringHashTable.cpp Parser.cpp Parser.hpp StringNode.cpp StringNode.hpp StringHasher.hpp PasswordGenerator.cpp PasswordGenerator.hpp)
add_subdirectory(Google_tests)
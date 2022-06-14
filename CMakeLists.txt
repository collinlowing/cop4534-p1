cmake_minimum_required(VERSION 3.23)
project(cop4534_p1)

set(CMAKE_CXX_STANDARD 14)

add_executable(cop4534_p1 main.cpp Cipher.cpp Cipher.hpp HashItem.cpp HashItem.hpp HashTable.cpp HashTable.hpp Parser.cpp Parser.hpp)
add_subdirectory(Google_tests)
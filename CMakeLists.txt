cmake_minimum_required(VERSION 3.14)
project(Hash_Generator)

set(CMAKE_CXX_STANDARD 17)

add_executable(Hash_Generator main.cpp hashFunction.cpp randomNum.cpp hashFunction.h tests.cpp tests.h timer.h randomNum.h)
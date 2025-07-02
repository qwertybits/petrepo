cmake_minimum_required(VERSION 3.31)
project(untitled1)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled1 main.cpp
        ntypes/NVector.h
        Kata.cpp
        Kata.h
        misc.h
        ntypes/NString.cpp
        ntypes/NString.h
        calculator/Lexer.cpp
        calculator/Lexer.h
        calculator/Parser.cpp
        calculator/Parser.h
        calculator/Calculator.h
        calculator/Token.cpp
        calculator/Token.h
)

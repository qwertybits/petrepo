//
// Created by ngixx on 01.07.2025.
//

#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <map>
#include <vector>

#include "Token.h"

namespace ngixx {

    inline std::map<char, TokenType> OPERATORS = {
        {'+', OPERATOR_PLUS}, {'-', OPERATOR_MINUS},
        {'*', OPERATOR_MULTIPLY}, {'/', OPERATOR_DIVIDE},
        {'(', LBRACKET}, {')', RBRACKET},
        {'^', OPERATOR_POW}
    };

    class Lexer {
        std::string input;
        int position = 0;
    public:
        Lexer() = default;
        explicit Lexer(std::string_view input);
        void setInput(std::string_view input);
        [[nodiscard]] std::vector<Token> tokenize();
    private:
        double tokenizeReadNumbers();
        [[nodiscard]] char peek() const;
        char nextChar();
        [[nodiscard]] char peekBack() const;
        static void analyzeExplicitMultiplying(std::vector<Token>& tokens) ;
    };
}

#endif //LEXER_H

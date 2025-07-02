//
// Created by ngixx on 02.07.2025.
//

#ifndef PARSER_H
#define PARSER_H
#include <vector>

#include "Lexer.h"

namespace ngixx {
    class Parser {
        std::vector<Token> tokens;
        int position = 0;
    public:
        Parser() = default;
        explicit Parser(const std::vector<Token>& tokens);
        double parse();
        void setTokens(std::vector<Token> tokens);
    private:
        Token nextToken();
        double expression();
        double term();
        double primary_expression();
        [[nodiscard]] Token peek() const;
    };
}

#endif //PARSER_H

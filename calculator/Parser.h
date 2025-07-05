//
// Created by ngixx on 02.07.2025.
//

#ifndef PARSER_H
#define PARSER_H
#include <functional>
#include <vector>

#include "Lexer.h"

namespace ngixx {
    class Parser {
        std::map<std::string, std::function<double(double)>> FUNCTIONS_MAP;
        std::map<std::string, double> CONSTANTS_VALUES;
        void initFunctions();
        void initConstants();
        double ansVariable = 0;
        std::vector<Token> tokens {};
        int position = 0;
    public:
        explicit Parser(const std::vector<Token>& tokens = {});
        double parse();
        void setTokens(const std::vector<Token>& tokens);
    private:
        const Token& nextToken();
        double expression();
        double term();
        double binary_expression();
        double primary_expression();
        [[nodiscard]] const Token& peek() const;
    };
}

#endif //PARSER_H

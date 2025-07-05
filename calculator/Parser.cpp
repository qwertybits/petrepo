//
// Created by ngixx on 02.07.2025.
//

#include "Parser.h"

#include <cmath>
#include <utility>

namespace ngixx {
    void Parser::initFunctions() {
        FUNCTIONS_MAP["sin"] = [](double x) -> double {
            return sin((M_PI*x)/180);
        };
        FUNCTIONS_MAP["cos"] = [](double x) -> double {
            return cos((M_PI*x)/180);
        };
    }

    void Parser::initConstants() {
        CONSTANTS_VALUES["pi"] = M_PI;
        CONSTANTS_VALUES["e"] = M_E;
        CONSTANTS_VALUES["ans"] = ansVariable;
    }

    Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens) {
        initFunctions();
        initConstants();
    }

    void Parser::setTokens(const std::vector<Token>& tokens) {
        this->tokens = tokens;
    }

    const Token& Parser::nextToken() {
        return tokens[position++];
    }

    const Token& Parser::peek() const {
        return tokens[position];
    }

    double Parser::parse() {
        this->position = 0;
        return (ansVariable = expression());
    }

    double Parser::expression() {
        auto t = term();
        while (position < tokens.size()) {
            auto tk = peek();
            if (tk.getType() == OPERATOR_PLUS) {
                nextToken();
                t += term();
            } else if (tk.getType() == OPERATOR_MINUS) {
                nextToken();
                t -= term();
            } else break;
        }
        return t;
    }

    double Parser::term() {
        double b = binary_expression();
        while (position < tokens.size()) {
            auto b_next = peek();
            if (b_next.getType() == OPERATOR_MULTIPLY) {
                nextToken();
                b *= binary_expression();
            } else if (b_next.getType() == OPERATOR_DIVIDE) {
                nextToken();
                double next = binary_expression();
                if (next == 0)
                    throw std::runtime_error("Divide by zero!");
                b /= next;
            } else
                break;
        }
        return b;
    }

    double Parser::binary_expression() {
        auto p = primary_expression();
        if (peek().getType() == OPERATOR_POW) {
            nextToken();
            p = pow(p, binary_expression());
        }
        return p;
    }

    double Parser::primary_expression() {
        auto tk = nextToken();
        if (tk.getType() == NUMBER_LITERAL) {
            return tk.getValue();
        }
        if (tk.getType() == LBRACKET) {
            double result = expression();
            auto next = nextToken();
            if (next.getType() != RBRACKET)
                throw std::runtime_error("Expected RBRACKET");
            return result;
        }

        //Перевірка на унарний мінус -number -(expression)
        if (tk.getType() == OPERATOR_MINUS) {
            return -primary_expression();
        }

        if (tk.getType() == IDENTIFIER && FUNCTIONS_MAP.contains(tk.getIdentifier())) {
            const auto func = FUNCTIONS_MAP[tk.getIdentifier()];
            return func(expression());
        }

        if (tk.getType() == IDENTIFIER && CONSTANTS_VALUES.contains(tk.getIdentifier())) {
            return CONSTANTS_VALUES[tk.getIdentifier()];
        }

        throw std::runtime_error("Unexpected token");
    }

}

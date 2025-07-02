//
// Created by ngixx on 02.07.2025.
//

#include "Parser.h"

#include <cmath>
#include <utility>

namespace ngixx {
    Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens) {}

    void Parser::setTokens(std::vector<Token> tokens) {
        this->tokens = std::move(tokens);
    }

    Token Parser::nextToken() {
        return tokens[position++];
    }

    Token Parser::peek() const {
        return tokens[position];
    }

    double Parser::parse() {
        this->position = 0;
        return expression();
    }

    double Parser::expression() {
        double t = term();
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
        double p = primary_expression();
        while (position < tokens.size()) {
            auto tk = peek();
            if (tk.getType() == OPERATOR_MULTIPLY) {
                nextToken();
                p *= term();
            } else if (tk.getType() == OPERATOR_DIVIDE) {
                nextToken();
                p /= term();
            } else break;
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
        throw std::runtime_error("Unexpected token");
    }

}

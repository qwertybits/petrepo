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
        throw std::runtime_error("Unexpected token");
    }

}

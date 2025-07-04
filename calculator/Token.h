//
// Created by ngixx on 02.07.2025.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <ostream>

namespace ngixx {
    enum TokenType {
        IDENTIFIER,
        NUMBER_LITERAL,
        OPERATOR_PLUS,
        OPERATOR_MINUS,
        OPERATOR_MULTIPLY,
        OPERATOR_DIVIDE,
        RBRACKET,
        LBRACKET,
        OPERATOR_POW,
        OPERATOR_MOD
    };


    class Token {
        double value{};
        TokenType type {};
        std::string identifier {};
    public:
        Token(TokenType type);
        Token(TokenType type, double value);
        [[nodiscard]] TokenType getType() const;
        [[nodiscard]] double getValue() const;
        friend std::ostream& operator<<(std::ostream& os, const Token& token);
    };
}

#endif //TOKEN_H

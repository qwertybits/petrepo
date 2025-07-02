//
// Created by ngixx on 02.07.2025.
//

#ifndef TOKEN_H
#define TOKEN_H

#include <ostream>

namespace ngixx {
    enum TokenType {
        NUMBER_LITERAL,
        OPERATOR_PLUS,
        OPERATOR_MINUS,
        OPERATOR_MULTIPLY,
        OPERATOR_DIVIDE,
        RBRACKET,
        LBRACKET,
        OPERATOR_POW
    };

    class Token {
        double value{};
        TokenType type;
    public:
        Token(TokenType type, double value);
        explicit Token(TokenType type);
        [[nodiscard]] TokenType getType() const;
        [[nodiscard]] double getValue() const;
        friend std::ostream& operator<<(std::ostream& os, const Token& token);
    };
}

#endif //TOKEN_H

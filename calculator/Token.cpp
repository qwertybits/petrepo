#include "Token.h"

namespace ngixx {
    TokenType Token::getType() const {
        return type;
    }

    double Token::getValue() const {
        return value;
    }

    Token::Token(TokenType type) : type(type) {}

    Token::Token(TokenType type, double value) : value(value), type(type) {}

    std::ostream& operator<<(std::ostream& os, const Token& token) {
        os << "(";
        switch (token.getType()) {
            case OPERATOR_PLUS:
                os << "PLUS)";
                return os;
            case OPERATOR_MINUS:
                os << "MINUS)";
                return os;
            case OPERATOR_MULTIPLY:
                os << "MULTIPLY)";
                return os;
            case OPERATOR_DIVIDE:
                os << "DIVIDE)";
                return os;
            case LBRACKET:
                os << "LBRACKET)";
                return os;
            case RBRACKET:
                os << "RBRACKET)";
                return os;
            case OPERATOR_POW:
                os << "POW)";
                return os;
            case OPERATOR_MOD:
                os << "MOD)";
                return os;
            default:
                os << "NUMBER_LITERAL:" << token.getValue() << ")";
                return os;
        }
    }
}
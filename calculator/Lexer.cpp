//
// Created by ngixx on 01.07.2025.
//

#include "Lexer.h"

namespace ngixx {

    Lexer::Lexer(const std::string& input) : input(input) {}

    std::vector<Token> Lexer::tokenize() {
        std::vector<Token> tokens;
        if (input.empty())
            throw std::runtime_error("Empty experssion");
        for (position = 0; position < input.size(); ) {
            //Обробляємо оператори
            if (OPERATORS.contains(peek())) {
                tokens.emplace_back(OPERATORS.at(peek()));
                analyzeExplicitMultiplying(tokens);
                nextChar();
            }
            //Обробляємо числа (поки що тільки цілі)
            else if (isdigit(peek())) {
                tokens.emplace_back(NUMBER_LITERAL, tokenizeReadNumbers());
            //Ігноруємо пробіли
            } else if (peek() == ' ' || peek() == '\t') {
                nextChar();
            } else {
                throw std::runtime_error("Cant resolve given expression");
            }
        }
        return tokens;
    }

    //Зчитує символи чисел і повертає складене число із них
    double Lexer::tokenizeReadNumbers() {
        double num = 0;
        while (position < input.size() && isdigit(peek())) {
            num = num * 10 + (peek() - '0'); // 2*10+2 = 22
            nextChar();
        }
        if (position < input.size() && peek() == '.') {
            nextChar();
            float factor = 10;
            while (position < input.size() && isdigit(peek())) {
                num = num + static_cast<float>(peek()-'0') / factor;
                nextChar();
                factor *= 10;
            }
        }
        return num;
    }

    void Lexer::setInput(const std::string& input) {
        this->input = input;
    }

    //Дивиться який символ наступний, не змінює position
    char Lexer::peek() const {
        return input[position];
    }

    //Повертає текущий символ і зміщює position
    char Lexer::nextChar() {
        return input[position++];
    }

    char Lexer::peekBack() const {
        return input[position - 1];
    }

    void Lexer::analyzeExplicitMultiplying(std::vector<Token>& tokens) {
        const auto current = tokens.end() - 1;
        const auto prev = tokens.end() - 2;
        if (!tokens.empty() && current->getType() == LBRACKET) {
            if (prev->getType() == RBRACKET) {
                tokens.insert(current, Token(OPERATOR_MULTIPLY));
            }
            if (prev->getType() == NUMBER_LITERAL) {
                tokens.insert(current, Token(OPERATOR_MULTIPLY));
            }
        }
    }


}





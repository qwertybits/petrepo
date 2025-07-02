//
// Created by ngixx on 01.07.2025.
//

#include "Lexer.h"

namespace ngixx {

    Lexer::Lexer(std::string_view input) : input(input) {}

    std::vector<Token> Lexer::tokenize() const {
        std::vector<Token> tokens;
        if (input.size() == 0)
            throw std::runtime_error("Empty experssion");
        for (int i = 0; i < input.size(); ) {
            //Обробляємо оператори
            if (OPERATORS.contains(input[i])) {
                tokens.emplace_back(OPERATORS.at(input[i]));
                ++i;
            }
            //Обробляємо числа (поки що тільки цілі)
            else if (isdigit(input[i])) {
                tokens.emplace_back(NUMBER_LITERAL, tokenizeReadNumbers(i));
            //Ігноруємо пробіли
            } else if (input[i] == ' ' || input[i] == '\t') {
                ++i;
            } else {
                throw std::runtime_error("Cant resolve expression");
            }
        }
        return tokens;
    }

    void Lexer::setInput(const std::string_view input) {
        this->input = input;
    }

    //Зчитує символи чисел і повертає складене число із нього
    double Lexer::tokenizeReadNumbers(int &i) const {
        int num = 0;
        while (i < input.size() && isdigit(input[i])) {
            num = num * 10 + (input[i] - '0'); //magic?, no, bro
            ++i;
        }
       return num;
    }

}





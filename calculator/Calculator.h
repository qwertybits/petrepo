//
// Created by ngixx on 02.07.2025.
//
#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "Lexer.h"
#include "Parser.h"

namespace NPrograms {

    using namespace ngixx;

    class Calculator {
        static constexpr std::string EXIT_COMMAND = "exit";
        static constexpr std::string PROMPT = "> ";
    public:
        static void run() {
            Lexer lexer {};
            Parser parser;
            double evalValue {};
            std::string input;
            while (true) {
                input = readLine();
                if (input == EXIT_COMMAND)
                    break;
                try {
                    lexer.setInput(input);
                    parser.setTokens(lexer.tokenize());
                    evalValue = parser.parse();
                    std::cout << evalValue << std::endl;
                } catch (std::runtime_error& e) {
                    std::cout << e.what() << std::endl;
                }
            }
        }
    private:
        static std::string readLine() {
            std::string line;
            std::cout << PROMPT;
            std::getline(std::cin, line);
            return line;
        }
    };
}

#endif //CALCULATOR_H

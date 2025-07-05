#include <iostream>

#include "ntypes/NVector.h"
#include "calculator/Calculator.h"

#include <cmath>


using namespace ngixx;

int main() {
    NPrograms::Calculator::run();
    // try {
    //     Lexer lexer("ans+2");
    //     const auto tokens = lexer.tokenize();
    //     Parser parser;
    //     parser.setTokens(tokens);
    //     for (const auto& token : tokens) {
    //         std::cout << token << "  ";
    //     }
    //     std::cout << std::endl;
    //     const auto result = parser.parse();
    //     std::cout << result << std::endl;
    // } catch (std::runtime_error &e) {
    //     std::cout << e.what() << std::endl;
    // }

    // std::cout << std::sin(90.0f) << std::endl;

    return 0;
}

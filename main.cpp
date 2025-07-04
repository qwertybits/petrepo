#include <iostream>

#include "ntypes/NVector.h"
#include "calculator/Calculator.h"

using namespace ngixx;

int main() {
    NPrograms::Calculator::run();
    // try {
    //     Lexer lexer("20+2(2+8)");
    //     auto tokens = lexer.tokenize();
    //     Parser parser;
    //     parser.setTokens(tokens);
    //     for (auto token : tokens) {
    //         std::cout << token << "  ";
    //     }
    //     std::cout << std::endl;
    //     auto result = parser.parse();
    //     std::cout << result << std::endl;
    // } catch (std::runtime_error &e) {
    //     std::cout << e.what() << std::endl;
    // }

    return 0;
}

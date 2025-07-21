#include <iostream>

#include "ntypes/NVector.h"
#include "calculator/Calculator.h"
#include "ntypes/HashTable.h"

using namespace ngixx;

int main() {
    // NPrograms::Calculator::run();
    // try {
    //     Lexer lexer("20+2(2+8)");
    //     auto tokens = lexer.tokenize();
    //     Parser parser(tokens);
    //     for (auto token : tokens) {
    //         std::cout << token << "  ";
    //     }
    //     std::cout << std::endl << parser.parse() << std::endl;
    // } catch (std::runtime_error &e) {
    //     std::cout << e.what() << std::endl;
    // }

    try {
        HashTable<std::string,int> map;
        map.add("ivan",200);
        map.add("xuylo",1245);
        map["zalupa"] = 2434;
        std::cout << map["zalupa"] << std::endl;
    } catch (std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }

    return 0;
}

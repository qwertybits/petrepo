#include <iostream>
#include <vector>
#include "Kata.h"
#include "misc.h"

int main() {
    std::vector<int> vec = {};
    ngixx::fillVectorWithRandom(vec, 5);
    ngixx::printVector(vec);
    auto folded = Kata::foldArray(vec, 1);
    ngixx::printVector(folded);
    return 0;
}

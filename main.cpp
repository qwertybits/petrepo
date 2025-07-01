#include "ntypes/NVector.h"
#include "Kata.h"
#include "misc.h"

using namespace ngixx;

void vectorSection() {
    try {
        NVector<int> v;
        fillVectorWithRandom(v, 10, 25);
        printVector(v);
        v.remove(5);
        printVector(v);
        std::cout << "size = " << v.sizeOf() << "\tcapacity = " << v.capacityOf() << std::endl;
    } catch (const std::out_of_range& ex) {
        std::cout << ex.what() << std::endl;
    }
}

void stringSection() {
    NString str = "hello world!";
    printNString(str);
}

int main() {
    // vectorSection();
    stringSection();
    return 0;
}

#include "ntypes/NVector.h"
#include "Kata.h"
#include "misc.h"

using namespace ngixx;

int main() {
    NVector<int> vec;
    try {
        fillVectorWithRandom(vec, 11, 100);
        printVector(vec);
        std::cout << "Vector size: " << vec.sizeOf() << "\t capacity: " << vec.capacityOf() << std::endl;
        std::cout << "Pop back result:" << vec.pop_back() << std::endl;
        printVector(vec);
        std::cout << "Vector size: " << vec.sizeOf() << "\t capacity: " << vec.capacityOf() << std::endl;
    } catch (std::out_of_range& err) {
        std::cout << err.what() << std::endl;
    }
    return 0;
}

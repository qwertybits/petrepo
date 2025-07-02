#include <iostream>

#include "misc.h"
#include "ntypes/NVector.h"

using namespace ngixx;

int main() {
    NVector v = {1,2,3,4,5};
    printVector(v);
    return 0;
}

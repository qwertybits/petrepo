//
// Created by ngixx on 30.06.2025.
//

#ifndef MISC_H
#define MISC_H

#include <iostream>
#include "ntypes/NVector.h"

namespace ngixx {
    template<typename T>
    void printVector(const std::vector<T>& array, int pos = 0) {
        for (int i = pos; i < array.size(); i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    template<typename T>
    void printVector(const NVector<T>& array, int pos = 0) {
        for (int i = pos; i < array.sizeOf(); i++) {
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }

    inline void foo(const std::vector<int>& array) {
        int maxElem = array[0];
        int maxIndex = 0;
        for (int i = 1; i < array.size(); i++) {
            if (array[i] > maxElem) {
                maxElem = array[i];
                maxIndex = i;
            }
        }
        printVector(array, maxIndex);
        std::cout << std::endl;
    }

    template<typename T>
    void fillVectorWithRandom(std::vector<T>& array, int count, int upRange, int downRange = 0) {
        srand(time(NULL));
        for (int i = 0; i < count; i++) {
            array.emplace_back(rand() % upRange);
        }
    }

    template<typename T>
    void fillVectorWithRandom(NVector<T>& array, int count, int upRange, int downRange = 0) {
        srand(time(NULL));
        for (int i = 0; i < count; i++) {
            array.add(rand() % upRange);
        }
    }
}

#endif //MISC_H

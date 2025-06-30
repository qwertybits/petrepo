//
// Created by ngixx on 30.06.2025.
//

#ifndef MISC_H
#define MISC_H

namespace ngixx {
    inline void printVector(const std::vector<int>& array, int pos = 0) {
        for (int i = pos; i < array.size(); i++) {
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

    inline void fillVectorWithRandom(std::vector<int>& array, int count) {
        srand(time(NULL));
        for (int i = 0; i < count; i++) {
            array.emplace_back(rand() % 10);
        }
    }
}

#endif //MISC_H

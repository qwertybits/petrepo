//
// Created by ngixx on 30.06.2025.
//

#ifndef MISC_H
#define MISC_H

#include <iostream>

#include "ntypes/NString.h"
#include "ntypes/NVector.h"

#include <vector>

namespace ngixx {
    ///Виводить елементи в векторі починаючи з заданої позиції, за умовчанням 0
    ///@param array масив
    ///@param pos позиція початку виводу
    ///@author ngixx
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

    ///Заповнює масив випадковими числами
    ///@param array посилання на масив який заповнюється
    ///@param count яку кількість заповнити
    ///@param upRange верхня границя значень
    ///@param downRange нижня границя значень
    ///@author ngixx
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

//
// Created by ngixx on 30.06.2025.
//

#ifndef KATA_H
#define KATA_H

#include <vector>
#include <string>

class Kata
{
public:
    ///Складає вектор пополам (сумуя елементи) n кількість разів (рекурсивна версія)
    ///@param runs кількість складань
    ///@author ngixx
    static std::vector<int> foldArray(const std::vector<int>& array, int runs);
    ///Шукає унікальне число в масиві, який заповнений однаковими числами
    ///@author ngixx
    static float findUnique(const std::vector<float>& array);

    static std::string toWierdCase(std::string_view str);
};

#endif //KATA_H

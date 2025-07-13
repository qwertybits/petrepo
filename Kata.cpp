//
// Created by ngixx on 30.06.2025.
//

#include "Kata.h"

#include <string>
#include <string_view>

std::vector<int> Kata::foldArray(const std::vector<int>& array, int runs) {
    std::vector<int> result;
    int middle = array.size() / 2; //знаходимо середину масиву
    for (int i = 0; i < middle; i++) {
        result.push_back(array[i] + array[array.size() - i - 1]);
    }
    if (array.size() % 2 != 0) { // якщо масив має непарну кількість елементів, додати середній в кінець
        result.push_back(array[middle]);
    }
    if (runs > 1) { // якщо ще є необхідність в складанні масиву, викликаємо наш метод ще раз
        return foldArray(result, runs - 1);
    } else { // інакше просто повертаємо результат, якщо немає необхідності ще раз складати
        return result;
    }
}

float Kata::findUnique(const std::vector<float>& array) {
    if (array[0]==array[1]) {
        for (int i = 2; i < array.size(); i++) {
            if (array[i]!=array[0]) {
                return array[i];
            }
        }
    }
    if (array[0]==array[2]) return array[1];
    return array[0];
}

std::string Kata::toWierdCase(std::string_view str) {
    std::string result{str};
    bool inWord = false;
    int wordLetterCount = 0;
    for (char & i : result) {
        if (i != ' ') {
            inWord = true;
        }
        else {
            inWord = false;
            wordLetterCount = 0;
        }
        if (inWord) {
            i = (wordLetterCount % 2 == 0) ? static_cast<char>(toupper(i))
                                                   : static_cast<char>(tolower(i));
            wordLetterCount++;
        }
    }
    return result;
}
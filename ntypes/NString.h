//
// Created by ngixx on 01.07.2025.
//

#ifndef NSTRING_H
#define NSTRING_H
#include "NVector.h"

namespace ngixx {

    int nStrlen(const char* str);

    class NString {
        NVector<char> vector;
    public:
        NString() = default;
        NString(const char* str);
        NString(const NString& other);
        char& operator[](int index);
        const char& operator[](int index) const;
        [[nodiscard]] int size() const;
        friend std::ostream &operator<<(std::ostream &os, const NString& nstring);
    };
}

#endif //NSTRING_H

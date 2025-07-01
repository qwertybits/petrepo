//
// Created by ngixx on 01.07.2025.
//

#ifndef NSTRING_H
#define NSTRING_H
#include "NVector.h"

namespace ngixx {

    int nStrlen(const char* str);

    class NString {
    private:
        NVector<char> vector;
    public:
        NString() = default;
        NString(const char* str);
        // NString(const NString& other);
        // NString& operator=(const NString& other);
        NString& operator=(const char* str);
        char& operator[](int index);
        const char& operator[](int index) const;
        int size() const;
    };
}

#endif //NSTRING_H

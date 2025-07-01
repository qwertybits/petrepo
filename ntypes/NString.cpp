//
// Created by ngixx on 01.07.2025.
//

#include "NString.h"

namespace ngixx {

    int nStrlen(const char *str) {
        int count = 0;
        while (str[count] != '\0')
            count++;
        return count;
    }

    NString::NString(const char *str) {
        for (int i = 0; i < nStrlen(str); i++) {
            vector.add(str[i]);
        }
    }
    NString& NString::operator=(const char *str) {
        *this = NString(str);
        return *this;
    }

    int NString::size() const {
        return vector.sizeOf();
    }

    const char &NString::operator[](int index) const {
        return vector[index];
    }

    char& NString::operator[](int index) {
        return vector[index];
    }


}

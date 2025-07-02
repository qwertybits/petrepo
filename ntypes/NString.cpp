//
// Created by ngixx on 01.07.2025.
//

#include "NString.h"

namespace ngixx {

    int nStrlen(const char *str) {
        int count;
        for (count = 0; str[count] != '\0'; ++count );
        return count;
    }
    NString::NString(const char *str) {
        for (int i = 0; i < nStrlen(str); i++) {
            vector.add(str[i]);
        }
    }

    NString::NString(const NString &other) {
        this->vector = other.vector;
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

    std::ostream &operator<<(std::ostream &os, const NString &nstring) {
        for (int i = 0; i < nstring.size(); i++) {
            os << nstring[i];
        }
        return os;
    }

}

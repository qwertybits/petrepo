//
// Created by ngixx on 30.06.2025.
//

#ifndef NVECTOR_H
#define NVECTOR_H
#include <stdexcept>
#include <iostream>

namespace ngixx {

    template<typename T>
    class NVector {
    public:
        static constexpr int DEFAULT_ALLOC_CAP = 10;
    private:
        T* data;
        int size{};
        int capacity{};
    public:

        NVector() {
            data = nullptr;
        }

        explicit NVector(int capacity) {
            data = new T[capacity];
            this->capacity = capacity;
        }

        ~NVector() {
            delete[] data;
        }

        void add(const T &obj) {
            if (data == nullptr) {
                data = new T[DEFAULT_ALLOC_CAP];
                capacity = DEFAULT_ALLOC_CAP;
            }
            if (size==capacity)
                expand_capacity();
            data[size++] = obj;
        }

        T& at(int index) {
            if (index >= 0 && index < size)
                return data[index];
            throw std::out_of_range("index out of range");
        }

        T& operator[](int index) {
            if (index >= 0 && index < size)
                return data[index];
            throw std::out_of_range("index out of range");
        }

        T& operator[](int index) const {
            if (index >= 0 && index < size)
                return data[index];
            throw std::out_of_range("index out of range");
        }

        auto sizeOf() const {
            return size;
        }

        auto capacityOf() const {
            return capacity;
        }

        T pop_back() {
            if (size == 0)
                throw std::out_of_range("vector is empty");
            return data[--size];
        }

    private:
        void expand_capacity() {
            capacity *= 2;
            T* new_data = new T[capacity];
            for (int i = 0; i < size; i++)
                new_data[i] = data[i];
            delete[] data;
            data = new_data;
        }
    };
}

#endif //NVECTOR_H

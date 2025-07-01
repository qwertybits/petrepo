//
// Created by ngixx on 30.06.2025.
//

#ifndef NVECTOR_H
#define NVECTOR_H

#include <algorithm>
#include <stdexcept>
#include <iostream>

namespace ngixx {

    template<typename T>
    class NVector {
    public:
        static constexpr int DEFAULT_ALLOC_CAP = 10;
    private:
        T* data = nullptr;
        int size{};
        int capacity{};
    public:

        NVector() = default;

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
                expandCapacity();
            data[size++] = obj;
        }

        T at(int index) {
            if (index >= 0 && index < size)
                return data[index];
            throw std::out_of_range("index out of range");
        }

        T& operator[](int index) {
            if (index >= 0 && index < size)
                return data[index];
            throw std::out_of_range("index out of range");
        }

        const T& operator[](int index) const {
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

        T popBack() {
            if (size == 0)
                throw std::out_of_range("vector is empty");
            return data[--size];
        }

        void remove(int index) {
            if (index >= 0 && index < size) {
                for (int i = index; i < size - 1; i++)
                    data[i] = data[i+1];
                data[size-1] = 0;
                size--;
                return;
            }
            throw std::out_of_range("index out of range");
        }

    private:
        void expandCapacity() {
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

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

        NVector(const NVector& other) {
            data = new T[other.capacity];
            this->capacity = other.capacity;
            this->size = other.size;
            for (int i = 0; i < this->size; i++) {
                data[i] = other.data[i];
            }
        }

        ~NVector() {
            delete[] data;
        }

        void add(const T &obj) {
            if (data == nullptr) {
                expandCapacity(DEFAULT_ALLOC_CAP);
            } else if (size==capacity) {
                expandCapacity(capacity * 2);
            }
            // ReSharper disable once CppDFANullDereference
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

        //геніальний свап
        NVector& operator=(NVector other) {
            std::swap(data, other.data);
            std::swap(capacity, other.capacity);
            std::swap(size, other.size);
            return *this;
        }

        auto sizeOf() const {
            return size;
        }

        auto capacityOf() const {
            return capacity;
        }

        [[nodiscard]] bool isEmpty() const {
            return size == 0;
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
                data[--size] = 0;
            } else
                throw std::out_of_range("index out of range");
        }

        void eraseAll() {
            delete[] data;
            data = new T[DEFAULT_ALLOC_CAP];
            capacity = DEFAULT_ALLOC_CAP;
            size = 0;
        }

    private:
        void expandCapacity(const int newCapacity) {
            capacity = newCapacity;
            T* new_data = new T[capacity];
            for (int i = 0; i < size; i++)
                new_data[i] = data[i];
            delete[] data;
            data = new_data;
        }
    };
}

#endif //NVECTOR_H

//
// Created by ngixx on 30.06.2025.
//

#ifndef NVECTOR_H
#define NVECTOR_H

template<typename T>
class NVector {
private:
    T* data;
    int size;
    int capacity;
public:
    NVector();
    NVector(int capacity);
    ~NVector();
    void add(const T& obj);
    void remove(int index);
    T* at(int index);
    T& operator[](int index);

};



#endif //NVECTOR_H

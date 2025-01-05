#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <exception>

template <typename T>  class Array {
    private:
    T* elements;
    unsigned int n;
    
    public:
    Array () {
        elements = NULL;
        n = 0;
    };

    Array (unsigned int size) {
        n = size;
        elements = new T[n]();
    };

    Array (const Array& src) {
        this->n = src.n;
        elements = new T[n]();
        for (unsigned int i = 0; i < n; ++i) {
            this->elements[i] = src.elements[i];
        }
    }

    Array& operator=(const Array& src)
    {
        if (this != &src) {
            delete[] elements;
            this->n = src.n;
            elements = new T[n];
            for (unsigned int i = 0; i < n; ++i) {
                this->elements[i] = src.elements[i];
            }
        }
        return *this;
    }

    T& operator[](unsigned int i) {
        if (i >= n) {
            throw std::out_of_range("Error : position out of bounds");
        }
        return elements[i];
    }

    const T& operator[] (unsigned int i) const {
        if (i >= n) {
            throw std::out_of_range("Error : position out of bounds");
        }
        return elements[i];
    }

    unsigned int size() const {
        return n;
    }

    ~Array() {
        delete[] elements;
    }
};

#endif
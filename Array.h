//
// Created by Ron Dahan on 20/06/2020.
//

#ifndef HW3PARTB_ARRAY_H
#define HW3PARTB_ARRAY_H

#include <iostream>



namespace mtm {

    class BadAccess : public std::exception {
    public:
        const char* what() const _NOEXCEPT override
        {
            return "Bad Access";
        }
    };


    template<class T>
    class Array {
        T *data;
        int length;
    public:
        explicit Array(int size = 10);

        Array(const Array<T> &a);

        ~Array();

        Array &operator=(const Array<T> &a);

        int size() const;

        T &operator[](int index);

        const T &operator[](int index) const;
    };


    template<class T>
    Array<T>::Array(int size) {
        data = new T[size];
        length = size;
    }

    template<class T>
    Array<T>::Array(const Array<T> &a) {
        data = new T[a.size()];
        length = a.size();
        for (int i = 0; i < a.size(); ++i) {
            data[i] = a[i];
        }
    }

    template<class T>
    Array<T>::~Array() {
        delete[] data;
    }

    template<class T>
    Array<T> &Array<T>::operator=(const Array<T> &a) {
        if (this == &a) {
            return this;
        }
        T *temp_array = new T[a.size()];
        delete[] data;
        for (int i = 0; i < a.size(); ++i) {
            try {
                temp_array[i] = a[i];
            }
            catch (const std::exception &e) {
                delete[] temp_array;
                throw e;
            }
        }
        data = temp_array;
        length = a.size();
        return *this;
    }

    template<class T>
    int Array<T>::size() const {
        return length;
    }

    template<class T>
    T &Array<T>::operator[](int index) {
        if (index < 0 || index >= this->size()) {
            throw BadAccess();
        }
        return data[index];
    }

    template<class T>
    const T &Array<T>::operator[](int index) const {
        if (index < 0 || index >= this->size()) {
            throw BadAccess();
        }
        return data[index];
    }
}

#endif //HW3PARTB_ARRAY_H

//
// Created by Ron Dahan on 20/06/2020.
//

#ifndef HW3PARTB_MATRIX_H
#define HW3PARTB_MATRIX_H

#include "Array.h"
#include "Auxiliaries.h"

namespace mtm {
    template<class T>
    class Matrix {
        Array<Array<T>> row;
        Dimensions dim;
        Dimensions getDimensions() const;
    public:
        class iterator;
        iterator begin();
        iterator end();
        class const_iterator;
        const_iterator begin() const;
        const_iterator end() const;
        explicit Matrix(const Dimensions& dimensions = Dimensions(1,1), int value = 0);
        Matrix(const Matrix& matrix);
        ~Matrix();
        Matrix& operator=(const Matrix& matrix);
        friend Matrix operator+(const Matrix& matrix1, const Matrix& matrix2);
        Matrix& operator+=(const int value);
        Matrix operator-() const ;
        friend Matrix operator-(const Matrix& matrix1, const Matrix& matrix2);
        int& operator()(int row_num,int col_num);
        const int& operator()(int row_num,int col_num) const;
        friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix);
        Matrix transpose() const ;
        static Matrix Identity(int dim);
        int height() const;
        int width() const;
        int size() const;
    };

    template <class T>
    std::ostream& operator<<(std::ostream& os, const Matrix<T>& matrix);

    template <class T>
    Matrix<T> operator+(const Matrix<T>& matrix1, const Matrix<T>& matrix2);
    template <class T>
    Matrix<T> operator+(const Matrix<T>& matrix, const int value);
    template <class T>
    Matrix<T> operator+(const int value, const Matrix<T>& matrix);
    template <class T>
    Matrix<T> operator-(const Matrix<T>& matrix1, const Matrix<T>& matrix2);
    template <class T>
    Matrix<T> operator<(Matrix<T>& matrix, int num);
    template <class T>
    Matrix<T> operator<=(Matrix<T>& matrix, int num);
    template <class T>
    Matrix<T> operator>(Matrix<T>& matrix, int num);
    template <class T>
    Matrix<T> operator>=(Matrix<T>& matrix, int num);
    template <class T>
    Matrix<T> operator==(Matrix<T>& matrix, int num);
    template <class T>
    Matrix<T> operator!=(Matrix<T>& matrix, int num);
    template <class T>
    bool any(const Matrix<T>& matrix);
    template <class T>
    bool all(const Matrix<T>& matrix);

    template <class T>
    class Matrix<T>::iterator{
        Matrix* matrix;
        int index;
        friend class IntMatrix;
        iterator(Matrix* matrix, int index);
    public:
        int& operator*();
        iterator& operator++(); // prefix (++it)
        iterator operator++(int);
        bool operator==(const iterator& it) const;
        bool operator!=(const iterator& it) const;
        iterator(const iterator&) = default;
        iterator& operator=(const iterator&) = default;
    };

    template <class T>
    class Matrix<T>::const_iterator{
        const Matrix* matrix;
        int index;
        friend class IntMatrix;
        const_iterator(const Matrix* matrix, int index);
    public:
        const int& operator*() const;
        const_iterator& operator++(); // prefix (++it)
        const_iterator operator++(int);
        bool operator==(const const_iterator& it) const;
        bool operator!=(const const_iterator& it) const;
        const_iterator(const const_iterator&) = default;
        const_iterator& operator=(const const_iterator&) = default;
    };
}

#endif //HW3PARTB_MATRIX_H

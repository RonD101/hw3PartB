//
// Created by Ron Dahan on 18/06/2020.
//

#ifndef HW3_INTMATRIX_H
#define HW3_INTMATRIX_H

#include "../Auxiliaries.h"

namespace mtm {
    class IntMatrix {
        int** row;
        Dimensions dim;
        Dimensions getDimensions() const;
    public:
        class iterator;
        iterator begin();
        iterator end();
        class const_iterator;
        const_iterator begin() const;
        const_iterator end() const;
        explicit IntMatrix(const Dimensions& dimensions = Dimensions(1,1), int value = 0);
        IntMatrix(const IntMatrix& matrix);
        ~IntMatrix();
        IntMatrix& operator=(const IntMatrix& matrix);
        friend IntMatrix operator+(const IntMatrix& matrix1, const IntMatrix& matrix2);
        IntMatrix& operator+=(const int value);
        IntMatrix operator-() const ;
        int& operator()(int row_num,int col_num);
        const int& operator()(int row_num,int col_num) const;
        friend std::ostream& operator<<(std::ostream& os, const IntMatrix& matrix);
        IntMatrix transpose() const ;
        static IntMatrix Identity(int dim);
        int height() const;
        int width() const;
        int size() const;
    };
    std::ostream& operator<<(std::ostream& os, const IntMatrix& matrix);
    IntMatrix operator+(const IntMatrix& matrix1, const IntMatrix& matrix2);
    IntMatrix operator+(const IntMatrix& matrix, const int value);
    IntMatrix operator+(const int value, const IntMatrix& matrix);
    IntMatrix operator-(const IntMatrix& matrix1, const IntMatrix& matrix2);
    IntMatrix operator<(IntMatrix& matrix, int num);
    IntMatrix operator<=(IntMatrix& matrix, int num);
    IntMatrix operator>(IntMatrix& matrix, int num);
    IntMatrix operator>=(IntMatrix& matrix, int num);
    IntMatrix operator==(IntMatrix& matrix, int num);
    IntMatrix operator!=(IntMatrix& matrix, int num);
    bool any(const IntMatrix& matrix);
    bool all(const IntMatrix& matrix);

    class IntMatrix::iterator{
        IntMatrix* matrix;
        int index;
        friend class IntMatrix;
        iterator(IntMatrix* matrix, int index);
    public:
        int& operator*();
        iterator& operator++(); // prefix (++it)
        iterator operator++(int);
        bool operator==(const iterator& it) const;
        bool operator!=(const iterator& it) const;
        iterator(const iterator&) = default;
        iterator& operator=(const iterator&) = default;
    };
    class IntMatrix::const_iterator{
        const IntMatrix* matrix;
        int index;
        friend class IntMatrix;
        const_iterator(const IntMatrix* matrix, int index);
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
#endif //HW3_INTMATRIX_H

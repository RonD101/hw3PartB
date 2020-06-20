//
// Created by Ron Dahan on 20/06/2020.
//

#ifndef HW3PARTB_MATRIX_H
#define HW3PARTB_MATRIX_H

#include "Array.h"
#include "Auxiliaries.h"
using std::cout;
using std::endl;

namespace mtm {


    template<class T>
    class Matrix {
        Array<Array<T>> row;
        Dimensions dim;
        Dimensions getDimensions() const;
    public:
        class AccessIllegalElement;
        class IllegalInitialization;
        class DimensionMismatch;
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

    // Function to get number of rows of the matrix
    template<class T>
    int Matrix<T>::height() const {
        return dim.getRow();
    }

    // Function to get number of columns of the matrix
    template<class T>
    int Matrix<T>::width() const {
        return dim.getCol();
    }

    // Function to get the total number of values in the matrix
    template<class T>
    int Matrix<T>::size() const {
        return this->width()*this->height();
    }

    template<class T>
    Dimensions Matrix<T>::getDimensions() const {
        return this->dim;
    }

//    template<class T>
//    Matrix<T>::Matrix(const Dimensions &dimensions, int value) {
//        try {
//            int dim_row = dimensions.getRow();
//            int dim_col = dimensions.getCol();
//        } catch (const mtm::Matrix<int>::IllegalInitialization &e){
//            cout<<e.what()<<endl;
//        }
//        //allocating rows
//        row = new int *[dim_row];
//        //allocating cols
//        for (int i = 0; i < dim_row; ++i)
//        {
//            row[i] = new int[dim_col];
//        }
//        //setting default value
//        for (int j = 0; j < dim_row; ++j)
//        {
//            for (int i = 0; i < dim_col; ++i)
//            {
//                (*this)(j,i) = value;
//            }
//        }
//    }

//    Matrix<class T> operator+(const Matrix<class T> &matrix1, const Matrix<class T> &matrix2) {
//        Matrix<class T> matrix(matrix1.getDimensions());
//        for (int i = 0; i < matrix.height(); ++i)
//        {
//            for (int j = 0; j < matrix.width(); ++j)
//            {
//                matrix(i,j) = matrix1(i,j) + matrix2(i,j);
//            }
//        }
//        return matrix;
//    }

//     template<> Matrix<class T> Matrix<class T>::transpose() const {
//        Dimensions d(this->width(),this->height());
//        Matrix matrix(d);
//        for (int j = 0; j < matrix.height(); ++j)
//        {
//            for (int i = 0; i < matrix.width(); ++i)
//            {
//                matrix(j,i) = (*this)(i,j);
//            }
//        }
//        return matrix;
//    }

//    template<class T>
//    Matrix::iterator Matrix<T>::begin() {
//        return Matrix::iterator();
//    }
//
//    template<class T>
//    Matrix::iterator Matrix<T>::end() {
//        return Matrix::iterator();
//    }
//
//    template<class T>
//    Matrix::const_iterator Matrix<T>::begin() const {
//        return Matrix::const_iterator();
//    }
//    template<class T>
//    Matrix::const_iterator Matrix<T>::end() const {
//        return Matrix::const_iterator();
//    }
//
//    template<class T>
//    Matrix<T>::Matrix(const Matrix &matrix) {
//
//    }
//
//    template<class T>
//    Matrix<T>::~Matrix() {
//
//    }
//
//    template<class T>
//    Matrix &Matrix<T>::operator=(const Matrix &matrix) {
//        return <#initializer#>;
//    }
//
//    template<class T>
//    Matrix &Matrix<T>::operator+=(const int value) {
//        return <#initializer#>;
//    }
//
//    template<class T>
//    Matrix Matrix<T>::operator-() const {
//        return Matrix();
//    }
//
//    Matrix operator-(const Matrix &matrix1, const Matrix &matrix2) {
//        return Matrix();
//    }
//
//    template<class T>
//    int &Matrix<T>::operator()(int row_num, int col_num) {
//        return <#initializer#>;
//    }
//
//    template<class T>
//    const int &Matrix<T>::operator()(int row_num, int col_num) const {
//        return <#initializer#>;
//    }
//
//    std::ostream &operator<<(std::ostream &os, const Matrix &matrix) {
//        return <#initializer#>;
//    }

    ///////////////////////////////////////////////////////
    ////////////// Exception classes //////////////////////
    ///////////////////////////////////////////////////////
    template <class T>
    class Matrix<T>::AccessIllegalElement  : public std::exception {
    public:
        const char* what() const noexcept override
        {
            return "Mtm matrix error: An attempt to access an illegal element";
        }
    };
    template <class T>
    class Matrix<T>::IllegalInitialization  : public std::exception {
    public:
        const char* what() const noexcept override
        {
            return "Mtm matrix error: Illegal initialization values";
        }
    };
    template <class T>
    class Matrix<T>::DimensionMismatch  : public std::exception {
        Dimensions m1;
        Dimensions m2;
        std::string out;
    public:
        DimensionMismatch(Dimensions m1, Dimensions m2):m1(m1),m2(m2),out("Mtm matrix error: Dimension mismatch: " + m1.toString() + " " + m2.toString()) {}
        const char* what() const noexcept override
        {
            return out.c_str();
        }
    };
    ////////////////////////////////////////////////////////////////////////////////////////
}

#endif //HW3PARTB_MATRIX_H

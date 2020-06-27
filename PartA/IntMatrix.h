//
// Created by Ron Dahan on 18/06/2020.
//

#ifndef HW3_INTMATRIX_H
#define HW3_INTMATRIX_H

#include "Auxiliaries.h"

/**
* Int typed Matrix
*
* Implements a int typed Matrix.
* The type of the matrix's value is int.
* The matrix has an internal iterator for external use. For all functions
* where the state of the iterator after calling that function is not stated,
* it is undefined. That is you cannot assume anything about it.
*
* The following functions are available:
*   the big three - constructor , destructor and copy constructor.
*   begin		- Return an iterator for the start of the matrix.
*   end		- Return an iterator for the end of the matrix.
*   transpose		- Returns a copy of the matrix transposed.
*   Identity	- Returns the Identity matrix.
*   height		    - Return the height of the matrix (amount of rows).
*   width  	    - Returns the width of the matrix (amount of columns).
*   size		- Return the amount of variables in matrix
*   any	    - Return true if any of the matrix's variable is different than 0, and false otherwise.
*   all		-  Return true if all of the matrix's variable is different than 0, and false otherwise.
*
* The following operators are available:
*   operator=      - Assignment of one matrix to the other
*   operator+=      - Add matrices and then assign
*   operator-(binary)   - Subtract one matrix from the other
*   operator-(unary)    - Return copy of the matrix with -value
*   operator()      - Return reference to value
*   operator<<      - Return a ostream value to print
*   operator+(Value)     - Add value to each element in matrix
*   operator+(Matrix)   - Return copy of added matrices
*   operator<,<=,>,>=,== ,!=     - Return a matrix of ones and zero depending on the result between
*                                          the two elements
*/

/**
*	mapGetFirst: Sets the internal iterator (also called current key element) to
*	the first key element in the map. There doesn't need to be an internal order
*  of the keys so the "first" key element is any key element.
*	Use this to start iterating over the map.
*	To continue iteration use mapGetNext
*
* @param map - The map for which to set the iterator and return the first
* 		key element.
* @return
* 	NULL if a NULL pointer was sent or the map is empty.
* 	The first key element of the map otherwise
*/

namespace mtm {
    class IntMatrix {
        int** row;
        Dimensions dim;
        Dimensions getDimensions() const;
    public:
        class iterator;

/**
*	begin:  Return a iterator for the top left element of the matrix.
*	Use this to start iterating over the matrix.
*
* @return
* 	The first element of the matrix
*/
        iterator begin();

/**
*	end:  Return a iterator for element after the last element in matrix.
*	Use this to stop iterating over the matrix.
*
* @return
* 	The one after the last element of the matrix
*/
        iterator end();

        class const_iterator;

/**
*	begin:  Return a iterator for the top left element of the matrix.
*   the element cannot be change
*	Use this to start iterating over const matrix.
*
* @return
* 	The first element of the matrix
*/
        const_iterator begin() const;
/**
*	end:  Return a iterator for element after the last element in matrix.
*	Use this to stop iterating over const matrix.
*
* @return
* 	The one after the last element of the matrix
*/
        const_iterator end() const;

/**
*	Constructor: create a new matrix
*
* @param
* dimensions - The dimension for the new matrix
* value - Initial value (optional)
* @return
* 	The new matrix
*/
        explicit IntMatrix(const Dimensions& dimensions, int value = 0);

/**
*	Copy Constructor: create a copy matrix
*
* @param
* matrix - The matrix which we copy the values from.
* @return
* 	The copied matrix
*/
        IntMatrix(const IntMatrix& matrix);

/**
*    Destructor: Destroy the matrix when her 'life' end.
*
* @return
* 	No Return Value.
*/
        ~IntMatrix();

/**
*	operator=: assign matrix
*
* @param
* matrix - The matrix which we copy the values from.
* @return
* 	The assigned matrix
*/
        IntMatrix& operator=(const IntMatrix& matrix);

/**
*	operator+=: add value to each element in matrix, and then assign the matrix
*
* @param
* value - The value to add for each element.
*
* @return
* 	The assigned matrix
*/
        IntMatrix& operator+=(const int value);

/**
*	operator-: return copied matrix with -values
*
* @return
* 	The copied matrix
*/
        IntMatrix operator-() const ;

/**
*	operator(): Return element from matrix
*
* @param
* rom_num - The row number of the element
* col_num - The column number of the element
* @return
* 	Reference to the element
*/
        int& operator()(int row_num,int col_num);

/**
*	operator(): Return a const element from matrix
*
* @param
* rom_num - The row number of the element
* col_num - The column number of the element
* @return
* 	Reference to the const element
*/
        const int& operator()(int row_num,int col_num) const;

/**
*	transpose: Returns a copy of the matrix transposed.
*
* @return
* 	The transposed matrix
*/
        IntMatrix transpose() const ;

/**
*	Identity: Returns a copy of Identity matrix.
*
* @param
* dim - the dimension of the Identity matrix
* @return
* 	The Identity matrix
*/
        static IntMatrix Identity(int dim);

/**
*	height: Returns the height of the matrix (amount of row).
*
* @return
* 	Amount of row
*/
        int height() const;

/**
*	width: Returns the width of the matrix (amount of columns).
*
* @return
* 	Amount of columns
*/
        int width() const;

/**
*	size: Returns the amount of element in matrix.
*
* @return
* 	Amount of elements
*/
        int size() const;
    };

/**
*	operator<<: Returns a osstream to print.
*
* @param
* os - ostream for the message to print
* matrix - the matrix to print
* @return
* 	The ostream
*/
    std::ostream& operator<<(std::ostream& os, const IntMatrix& matrix);

/**
*	operator+: Returns a copy of the added matrix.
*
* @param
* matrix1 - First matrix to add
* matrix2 - Second matrix to add
* @return
* 	The added matrix
*/
    IntMatrix operator+(const IntMatrix& matrix1, const IntMatrix& matrix2);

/**
*	operator+: Returns a copy of the added matrix with value.
*
* @param
* matrix - The matrix to copy.
* value - The value to add for each element.
* @return
* 	The added matrix
*/
    IntMatrix operator+(const IntMatrix& matrix, const int value);

/**
*	operator+: Returns a copy of the added matrix with value.
*
* @param
* value - The value to add for each element.
* matrix - The matrix to copy.
* @return
* 	The added matrix
*/
    IntMatrix operator+(const int value, const IntMatrix& matrix);

/**
*	operator-: Returns a copy of the subtract matrix.
*
* @param
* matrix1 - The matrix to subtract from
* matrix2 - The matrix to subtract
* @return
* 	The subtracted matrix
*/
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

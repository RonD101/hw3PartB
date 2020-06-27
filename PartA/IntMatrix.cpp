#include "IntMatrix.h"

using mtm::IntMatrix;

// constructor for IntMatrix
IntMatrix::IntMatrix(const Dimensions& dimensions, int value):dim(dimensions)
{
    int dim_row = dimensions.getRow();
    int dim_col = dimensions.getCol();
    //allocating rows
    row = new int *[dim_row];
    //allocating cols
    for (int i = 0; i < dim_row; ++i)
    {
        row[i] = new int[dim_col];
    }
    //setting default value
    for (int j = 0; j < dim_row; ++j)
    {
        for (int i = 0; i < dim_col; ++i)
        {
            (*this)(j,i) = value;
        }
    }
}

// destructor for IntMatrix
IntMatrix::~IntMatrix()
{
    for (int i = 0; i < dim.getRow(); ++i)
    {
        delete[] row[i];
    }
    delete[] row;
}

// Function returns an identity matrix with specified dimensions
IntMatrix IntMatrix::Identity(int dim) {
    Dimensions d(dim,dim);
    IntMatrix matrix = IntMatrix(d);
    for (int i = 0; i < matrix.height(); ++i) {
        matrix(i,i) = 1;
    }
    return matrix;
}

// Output function prints IntMatrix using function printMatrix
std::ostream& mtm::operator<<(std::ostream& os, const IntMatrix& matrix) {
    int* flatMatrix = new int[matrix.size()];
    int counter = 0;
    Dimensions dims(matrix.height(), matrix.width());
    for (int i = 0; i < matrix.height(); ++i) {
        for (int j = 0; j < matrix.width(); ++j) {
            flatMatrix[counter++] = matrix(i,j);
        }
    }
    os << (printMatrix(flatMatrix, dims));
    delete[] flatMatrix;
    return os;
}

// Function to get number of rows of the matrix
int IntMatrix::width() const {
    return dim.getCol();
}

// Function to get number of columns of the matrix
int IntMatrix::height() const {
    return dim.getRow();
}

// Function to get the total number of values in the matrix
int IntMatrix::size() const {
    return (this->height())*(this->width());
}

// operator= for IntMatrix
IntMatrix& IntMatrix::operator=(const IntMatrix& matrix)
{
    if(this == & matrix)
    {
        return *this;
    }
    for (int i = 0; i < this->height(); ++i)
    {
        delete[] row[i];
    }
    delete[] row;
    dim = matrix.dim;
    //allocating rows
    row = new int *[this->height()];
    //allocating cols
    for (int i = 0; i < this->height(); ++i)
    {
        row[i] = new int[this->width()];
    }
    //setting new values
    for (int j = 0; j < this->height(); ++j)
    {
        for (int i = 0; i < this->width(); ++i)
        {
            (*this)(j,i) = matrix(j,i);
        }
    }
    return *this;
}

// Function to check which elements in the matrix are smaller than the int passed
// Returns new matrix with these rules:
// Smaller values become 1
// Larger values become 0
IntMatrix mtm::operator<(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 0; j < matrix_new.height(); ++j)
    {
        for (int i = 0; i < matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) < num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}

// Function to check which elements in the matrix are equal or smaller than the int passed
// Returns new matrix with these rules:
// Smaller or equal values become 1
// Larger values become 0
IntMatrix mtm::operator<=(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 0; j < matrix_new.height(); ++j)
    {
        for (int i = 0; i < matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) <= num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}

// Function to check which elements in the matrix are larger than the int passed
// Returns new matrix with these rules:
// Larger values become 1
// Smaller values become 0
IntMatrix mtm::operator>(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 0; j < matrix_new.height(); ++j)
    {
        for (int i = 0; i < matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) > num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}

// Function to check which elements in the matrix are equal or larger than the int passed
// Returns new matrix with these rules:
// Larger or equal values become 1
// Smaller values become 0
IntMatrix mtm::operator>=(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 0; j < matrix_new.height(); ++j)
    {
        for (int i = 0; i < matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) >= num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}

// Function to check which elements in the matrix are equal to the int passed
// Returns new matrix with these rules:
// Equal values become 1
// Unequal values become 0
IntMatrix mtm::operator==(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 0; j < matrix_new.height(); ++j)
    {
        for (int i = 0; i < matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) == num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}

// Function to check which elements in the matrix are unequal to the int passed
// Returns new matrix with these rules:
// Unequal values become 1
// Equal values become 0
IntMatrix mtm::operator!=(IntMatrix& matrix, int num)
{
    IntMatrix matrix_new(matrix);
    for (int j = 0; j < matrix_new.height(); ++j)
    {
        for (int i = 0; i < matrix_new.width(); ++i)
        {
            if(matrix_new(j,i) != num)
            {
                matrix_new(j,i) = 1;
            } else
            {
                matrix_new(j,i) = 0;
            }
        }
    }
    return matrix_new;
}

// Function returns a transposed matrix
IntMatrix IntMatrix::transpose() const
{
    Dimensions d(this->width(),this->height());
    IntMatrix matrix(d);
    for (int j = 0; j < matrix.height(); ++j)
    {
        for (int i = 0; i < matrix.width(); ++i)
        {
            matrix(j,i) = (*this)(i,j);
        }
    }
    return matrix;
}

// Function returns new matrix which is the sum of the 2 matrices passed
IntMatrix mtm::operator+(const IntMatrix &matrix1, const IntMatrix &matrix2)
{

    IntMatrix matrix(Dimensions(matrix1.height(),matrix1.width()));
    for (int i = 0; i < matrix.height(); ++i)
    {
        for (int j = 0; j < matrix.width(); ++j)
        {
            matrix(i,j) = matrix1(i,j) + matrix2(i,j);
        }
    }
    return matrix;
}

// Function returns new matrix which is the subtraction of the 2 matrices passed
IntMatrix IntMatrix::operator-() const {
    IntMatrix matrix(this->getDimensions());
    for (int j = 0; j < matrix.height(); ++j)
    {
        for (int i = 0; i < matrix.width(); ++i)
        {
            matrix(j,i) = -(*this)(j,i);
        }
    }
    return matrix;
}

// Copy constructor for IntMatrix
IntMatrix::IntMatrix(const IntMatrix &matrix):dim(matrix.height(),matrix.width()) {
    //allocating rows
    row = new int *[matrix.height()];
    //allocating cols
    for (int i = 0; i < matrix.height(); ++i)
    {
        row[i] = new int[matrix.width()];
    }
    for (int i = 0; i < this->height() ; ++i) {
        for (int j = 0; j < this->width(); ++j) {
            (*this)(i,j) = matrix(i,j);
        }
    }
}

// function returns the dimensions of this matrix
mtm::Dimensions IntMatrix::getDimensions() const {
    return this->dim;
}

// function returns the contents of the IntMatrix int the coordinates row_num, col_num
// e.g int value = matrix(i, j)
int& IntMatrix::operator()(int row_num, int col_num) {
    return row[row_num][col_num];
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
const int& IntMatrix::operator()(int row_num, int col_num) const {
    return row[row_num][col_num];
}

IntMatrix mtm::operator-(const IntMatrix &matrix1, const IntMatrix &matrix2) {
    return matrix1 + -matrix2;
}

IntMatrix& IntMatrix::operator+=(const int value) {
    IntMatrix m(this->getDimensions(),value);
    *this = *this + m;
    return *this;
}


// begin method returns iterator to first element of IntMatrix
IntMatrix::iterator IntMatrix::begin()
{
    return iterator(this,1);
}

// begin method returns iterator to last element of IntMatrix
IntMatrix::iterator IntMatrix::end()
{
    return iterator(this,this->size() + 1);
}

IntMatrix::const_iterator IntMatrix::begin() const {
    return const_iterator(this,1);
}

IntMatrix::const_iterator IntMatrix::end() const {
    return const_iterator(this,this->size() + 1);
}

IntMatrix mtm::operator+(const IntMatrix& matrix, const int value){
    IntMatrix m(matrix);
    m += value;
    return m;
}

IntMatrix mtm::operator+(const int value, const IntMatrix& matrix){
    return matrix + value;
}

// Function checks if the matrix passed has at least one element whose value is true.
// If so, returns true, if not returns false
bool mtm::any(const IntMatrix& matrix)
{
    for (int i = 0; i <matrix.height(); ++i)
    {
        for (int j = 0; j < matrix.width(); ++j)
        {
            if(matrix(i,j) != 0)
            {
                return true;
            }
        }
    }
    return false;
}

// Function checks if all elements if the matrix passed have the value of true.
// If so, returns true, if not returns false
bool mtm::all(const IntMatrix& matrix)
{
    for (int i = 0; i < matrix.height(); ++i)
    {
        for (int j = 0; j < matrix.width(); ++j)
        {
            if(matrix(i,j) == 0)
            {
                return false;
            }
        }
    }
    return true;
}

IntMatrix::iterator::iterator(IntMatrix *matrix, int index):matrix(matrix),index(index) {}

// operator* returns the element pointed to by the iterator
int& IntMatrix::iterator::operator*() {
    int col_index = index % matrix->width();
    if(col_index == 0){
        col_index = matrix->width();
    }
    int row_index;
    if(index % matrix->width() == 0)
    {
        row_index = index/matrix->width();
    } else
    {
        row_index = (index/matrix->width() )+ 1;
    }
    return (*matrix)(row_index - 1, col_index - 1);
}

// operator== returns true if value in iterator is equal to that of other iterator
bool IntMatrix::iterator::operator==(const IntMatrix::iterator &it) const {
    return this->index == it.index;
}

// operator!= returns true if value in iterator is unequal to that of other iterator
bool IntMatrix::iterator::operator!=(const IntMatrix::iterator &it) const {
    return this->index != it.index;
}

// operator++ advances iterator to next element. Advancing past the end() iterator is undefined
IntMatrix::iterator& IntMatrix::iterator::operator++() {
    index++;
    return *this;
}

// ++operator advances iterator to next element. Advancing past the end() iterator is undefined
IntMatrix::iterator IntMatrix::iterator::operator++(int) {
    iterator result = *this;
    ++(*this);
    return result;
}

IntMatrix::const_iterator::const_iterator(const IntMatrix *matrix, int index):matrix(matrix),index(index) {}

const int& IntMatrix::const_iterator::operator*() const {
    int col_index = index % matrix->width();
    if(col_index == 0){
        col_index = matrix->width();
    }
    int row_index;
    if(index % matrix->width() == 0)
    {
        row_index = index/matrix->width();
    } else
    {
        row_index = (index/matrix->width() )+ 1;
    }
    return (*matrix)(row_index - 1, col_index - 1);
}

bool IntMatrix::const_iterator::operator==(const IntMatrix::const_iterator &it) const {
    return this->index == it.index;
}

bool IntMatrix::const_iterator::operator!=(const IntMatrix::const_iterator &it) const {
    return this->index != it.index;
}

IntMatrix::const_iterator& IntMatrix::const_iterator::operator++() {
    index++;
    return *this;
}

IntMatrix::const_iterator IntMatrix::const_iterator::operator++(int) {
    const_iterator result = *this;
    ++(*this);
    return result;
}
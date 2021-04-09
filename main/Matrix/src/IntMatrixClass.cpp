#include <cstring>
#include "../include/IntMatrixClass.hpp"
#include "../include/FloatVectorClass.hpp"


#include <iostream>

IntMatrixClass::IntMatrixClass(size_t row, size_t column) {
    _row = row;
    _column = column;

    _matrix = new int64_t[_row * _column]{};

    std::memset(_matrix, 0, _row * _column);

}

IntMatrixClass::IntMatrixClass(size_t row) {
    _row = row;
    _column = 1;

    _matrix = new int64_t[_row]{};

}


IntMatrixClass::~IntMatrixClass() {
    delete[] _matrix;
}


int64_t *IntMatrixClass::operator[](size_t value) {
    return &_matrix[value * _column];
}


IntMatrixClass operator*(IntMatrixClass &left, IntMatrixClass &right) {

    if (!left.IfThisMultiplyebleOn(right)) {
        IntMatrixClass newIntMatrixClass(0, 0);
        return newIntMatrixClass;
    }

    IntMatrixClass newIntMatrix(left.GetRows(), right.GetColumns());

    for (size_t m = 0; m < left.GetRows(); m++) {
        for (size_t k = 0; k < left.GetColumns(); k++) {
            for (size_t n = 0; n < left.GetColumns(); n++) {
                newIntMatrix[m][k] += left[m][n] * right[n][k];
            }
        }
    }

    return newIntMatrix;

}


IntMatrixClass operator*(IntMatrixClass &left, FloatMatrixClass &right) {
    if (!left.IfThisMultiplyebleOn(right)) {
        IntMatrixClass newIntMatrixClass(0, 0);
        return newIntMatrixClass;
    }

    IntMatrixClass newIntMatrix(left.GetRows(), right.GetColumns());

    for (size_t m = 0; m < left.GetRows(); m++) {
        for (size_t k = 0; k < right.GetColumns(); k++) {
            for (size_t n = 0; n < left.GetColumns(); n++) {
                newIntMatrix[m][k] += left[m][n] * right[n][k];
            }
        }
    }
    return newIntMatrix;
}


IntMatrixClass& IntMatrixClass::operator=(int64_t *matrix[]) {

    for (size_t row = 0; row < this->_row; row++) {
        for (size_t column = 0; column < this->_column; column++) {
            this->operator[](row)[column] = matrix[row][column];
        }
    }

    return *this;
}

IntMatrixClass& IntMatrixClass::operator=(int64_t *matrix) {
    for (size_t i = 0; i <= this->_column * this->_row; i++) {
        this->_matrix[i] = matrix[i];
    }

    return *this;
}

IntMatrixClass::IntMatrixClass(const IntMatrixClass &matrix) {

    this->_column = matrix._column;
    this->_row = matrix._row;
    this->_matrix = new int64_t[this->_row * this->_row];

    for (size_t i = 0; i <= this->_column * this->_row; i++) {
        this->_matrix[i] = matrix._matrix[i];
    }
}

int64_t *IntMatrixClass::operator[](size_t value) const {
    return &_matrix[value * _column];
}

std::ostream &operator<<(std::ostream &stream, const IntMatrixClass &matrixClass) {
    for (size_t row = 0; row < matrixClass.GetRows(); row++) {
        for (size_t column = 0; column < matrixClass.GetColumns(); column++) {
            stream << (matrixClass.operator[](row)[column]) << ' ';
        }
        stream << std::endl;
    }
    return stream;
}

FloatVectorClass operator*(const IntMatrixClass &matrix, const FloatVectorClass &vector) {
    if (matrix._column != vector.Length()) {
        FloatVectorClass floatVectorClass(0);
        return floatVectorClass;
    }

    FloatVectorClass floatVectorClass(matrix._row);

    for (size_t m = 0; m < matrix._row; m++) {
        for (size_t n = 0; n < vector._length; n++) {
            floatVectorClass[m] += matrix.operator[](m)[n] * vector[n];


        }
    }
    return floatVectorClass;
}
#include "../include/FloatMatrixClass.hpp"

FloatMatrixClass::FloatMatrixClass(size_t row, size_t column) {
    _row = row;
    _column = column;

    _matrix = new double[_row * _column]{};

}

FloatMatrixClass::FloatMatrixClass(size_t row) {
    _row = row;
    _column = 1;

    _matrix = new double[_row]{};

}

FloatMatrixClass::~FloatMatrixClass() {
    delete[] _matrix;
}

double *FloatMatrixClass::operator[](size_t value) { return &_matrix[value * _column]; }

double *FloatMatrixClass::operator[](size_t value) const { return &_matrix[value * _column]; }

FloatMatrixClass FloatMatrixClass::operator*(FloatMatrixClass &right) {
    if (!this->IfThisMultiplyebleOn(right)) {
        FloatMatrixClass newFloatMatrix(0, 0);
        return newFloatMatrix;
    }

    FloatMatrixClass newFloatMatrix(this->GetRows(), right.GetColumns());

    for (size_t m = 0; m < this->GetRows(); m++) {
        for (size_t k = 0; k < right.GetColumns(); k++) {
            for (size_t n = 0; n < this->GetColumns(); n++) {
                newFloatMatrix[m][k] += this->operator[](m)[n] * right[n][k];
            }
        }
    }
    return newFloatMatrix;
}


FloatMatrixClass &FloatMatrixClass::operator=(double **right) {
    for (size_t i = 0; i < this->GetRows(); i++) {

        for (size_t j = 0; j < this->GetColumns(); j++) {

            this->operator[](i)[j] = right[i][j];
        }
    }

    return *this;
}

FloatMatrixClass &FloatMatrixClass::operator=(double *right) {
    for (size_t i = 0; i <= this->_column * this->_row; i++) {
        this->_matrix[i] = right[i];
    }

    return *this;
}

FloatMatrixClass &FloatMatrixClass::operator=(float *right) {
    for (size_t i = 0; i <= this->_column * this->_row; i++) {
        this->_matrix[i] = right[i];
    }

    return *this;
}

FloatMatrixClass::FloatMatrixClass(const FloatMatrixClass &matrix) {

    this->_column = matrix._column;
    this->_row = matrix._row;
    this->_matrix = new double[this->_row * this->_row];

    for (size_t i = 0; i <= this->_column * this->_row; i++) {
        this->_matrix[i] = matrix._matrix[i];
    }
}


std::ostream &operator<<(std::ostream &stream, const FloatMatrixClass &matrixClass) {
    for (size_t row = 0; row < matrixClass.GetRows(); row++) {
        for (size_t column = 0; column < matrixClass.GetColumns(); column++) {
            stream << (matrixClass.operator[](row)[column]) << ' ';
        }
        stream << std::endl;
    }
    return stream;
}



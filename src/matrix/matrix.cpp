#include "matrix.h"

#include <cassert>
#include <iomanip>

template class Matrix<int32_t>;

template<class T>
Matrix<T>::Matrix(const uint32_t column_size, const uint32_t row_size) : column_size(column_size), row_size(row_size) {
    data.reserve(column_size * row_size);
    for(auto& c_data : data) {
        c_data = 0;
    }
}

template<class T>
Matrix<T>::Matrix(const uint32_t column_size, const uint32_t row_size, const std::vector<T> data) : column_size(column_size), row_size(row_size), data(data) {
    // TODO: check the size of the matrix and input data
}

template<class T>
Matrix<T>::Matrix(const Matrix<T>& rhs) {
    assert(column_size == rhs.column_size);
    assert(row_size == rhs.row_size);
    column_size = rhs.column_size;
    row_size = rhs.row_size;
    const uint32_t matrix_size = (rhs.column_size * rhs.row_size);
    data.reserve(matrix_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        data[i] = rhs.data[i];
    }
}

template<class T>
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    assert(column_size == rhs.column_size);
    assert(row_size == rhs.row_size);
    this->column_size = rhs.column_size;
    this->row_size = rhs.row_size;
    const uint32_t matrix_size = (rhs.column_size * rhs.row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        this->data[i] = rhs.data[i];
    }
    return *this;
}

// TODO: https://www.cplusplus.com/doc/tutorial/classes2/#:~:text=Move%20constructor%20and%20assignment
template<class T>
Matrix<T>::Matrix(Matrix<T>&& rhs) {
    assert(column_size == rhs.column_size);
    assert(row_size == rhs.row_size);
    column_size = rhs.column_size;
    row_size = rhs.row_size;
    data = rhs.data;
}

// TODO: https://www.cplusplus.com/doc/tutorial/classes2/#:~:text=Move%20constructor%20and%20assignment
template<class T>
Matrix<T>& Matrix<T>::operator=(Matrix<T>&& rhs) {
    assert(column_size == rhs.column_size);
    assert(row_size == rhs.row_size);
    column_size = rhs.column_size;
    row_size = rhs.row_size;
    data = rhs.data;
    return *this;
}

template<class T>
Matrix<T>::~Matrix() {
}

template<class T>
const uint32_t Matrix<T>::getColumnSize() {
    return column_size;  
}

template<class T>
const uint32_t Matrix<T>::getRowSize() {
    return row_size;  
}

template<class T>
const std::vector<T> Matrix<T>::getData() {
    return data;  
}

template<class T>
void Matrix<T>::setValueByIndex(const uint32_t column_index, const uint32_t row_index, const T value) {
    assert((column_index < 0U) && (column_index > column_size - 1U));
    assert((row_index < 0U) && (row_index > row_size - 1U));
    data[(row_index * column_size) + column_index] = value;
}

template<class T>
const T Matrix<T>::getValueByIndex(const uint32_t column_index, const uint32_t row_index) {
    assert((column_index < 0U) && (column_index > column_size - 1U));
    assert((row_index < 0U) && (row_index > row_size - 1U));
    return data[(row_index * column_size) + column_index];
}

template<class T>
void Matrix<T>::displayData() {
    const uint32_t matrix_size = (column_size * row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        // TODO: define a configuration parameter for setw
        std::cout << std::setw(4) << data[i];
        if (((i + 1) % column_size) == 0U) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

template<class T>
void Matrix<T>::dotProduct(const Matrix<T>& rhs) {
    assert(column_size == rhs.column_size);
    assert(row_size == rhs.row_size);
    const uint32_t matrix_size = (column_size * row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        data[i] *= rhs.data[i];
    }
}

template<class T>
void Matrix<T>::dotQuotient(const Matrix<T>& rhs) {
    assert(column_size == rhs.column_size);
    assert(row_size == rhs.row_size);
    const uint32_t matrix_size = (column_size * row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        data[i] /= rhs.data[i];
    }
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& rhs) const {
    assert(column_size == rhs.column_size);
    assert(row_size == rhs.row_size);
    Matrix<T> result {rhs.column_size, rhs.row_size};
    const uint32_t matrix_size = (column_size * row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        result.data[i] = data[i] + rhs.data[i];
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& rhs) const {
    assert(column_size == rhs.column_size);
    assert(row_size == rhs.row_size);
    Matrix<T> result {rhs.column_size, rhs.row_size};
    const uint32_t matrix_size = (column_size * row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        result.data[i] = data[i] - rhs.data[i];
    }
    return result;
}

template<class T>
bool Matrix<T>::operator==(const Matrix<T>& rhs) const {
    if (this->column_size != rhs.column_size) {
        return false;
    }
    if (this->row_size != rhs.row_size) {
        return false;
    }
    const uint32_t matrix_size = (rhs.column_size * rhs.row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        if (this->data[i] != rhs.data[i]) {
            return false;
        }
    }
    return true;
}

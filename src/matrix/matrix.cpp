#include <cassert>
#include <iomanip>

#include "matrix.h"

template class Matrix<int32_t>;

template<class T>
Matrix<T>::Matrix(const uint32_t column_size, const uint32_t row_size) : column_size(column_size), row_size(row_size) {
    const uint32_t matrix_size = (column_size * row_size);
    data.reserve(matrix_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        data[i] = 0;
    }
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
    assert((column_index < 0U) && (column_index > this->column_size - 1U));
    assert((row_index < 0U) && (row_index > this->row_size - 1U));

    data[(row_index * this->column_size) + column_index] = value;
}

template<class T>
const T Matrix<T>::getValueByIndex(const uint32_t column_index, const uint32_t row_index) {
    assert((column_index < 0U) && (column_index > this->column_size - 1U));
    assert((row_index < 0U) && (row_index > this->row_size - 1U));

    return data[(row_index * this->column_size) + column_index];
}

template<class T>
void Matrix<T>::displayData() {
    const uint32_t matrix_size = (this->column_size * this->row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        // TODO: define a configuration parameter for setw
        std::cout << std::setw(4) << data[i];
        if (((i + 1) % this->column_size) == 0U) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

template<class T>
void Matrix<T>::dotProduct(const Matrix<T>& m) {
    assert(this->column_size == m.column_size);
    assert(this->row_size == m.row_size);
    const uint32_t matrix_size = (this->column_size * this->row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        this->data[i] *= m.data[i];
    }
}

template<class T>
void Matrix<T>::dotQuotient(const Matrix<T>& m) {
    assert(this->column_size == m.column_size);
    assert(this->row_size == m.row_size);
    const uint32_t matrix_size = (this->column_size * this->row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        this->data[i] /= m.data[i];
    }
}

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T>& m) {
    assert(this->column_size == m.column_size);
    assert(this->row_size == m.row_size);
    Matrix<T> result {m.column_size, m.row_size};
    const uint32_t matrix_size = (this->column_size * this->row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        result.data[i] = this->data[i] + m.data[i];
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator-(const Matrix<T>& m) {
    assert(this->column_size == m.column_size);
    assert(this->row_size == m.row_size);
    Matrix<T> result {m.column_size, m.row_size};
    const uint32_t matrix_size = (this->column_size * this->row_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        result.data[i] = this->data[i] - m.data[i];
    }
    return result;
}

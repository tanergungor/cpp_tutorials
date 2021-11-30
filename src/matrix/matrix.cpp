#include "matrix.h"

Matrix::Matrix(const uint32_t column_size, const uint32_t row_size) : column_size(column_size), row_size(row_size) {
    const uint32_t matrix_size = (column_size * row_size);
    data.reserve(matrix_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        data[i] = 0;
    }
}

const uint32_t Matrix::getColumnSize() {
    return column_size;  
}

const uint32_t Matrix::getRowSize() {
    return row_size;  
}

const std::vector<int32_t> Matrix::getData() {
    return data;  
}

void Matrix::setValueByIndex(const uint32_t column_index, const uint32_t row_index, const int32_t value) {
    assert((column_index < 0U) && (column_index > this->column_size - 1U));
    assert((row_index < 0U) && (row_index > this->row_size - 1U));

    data[(row_index * this->column_size) + column_index] = value;
}

const int32_t Matrix::getValueByIndex(const uint32_t column_index, const uint32_t row_index) {
    assert((column_index < 0U) && (column_index > this->column_size - 1U));
    assert((row_index < 0U) && (row_index > this->row_size - 1U));

    return data[(row_index * this->column_size) + column_index];
}

void Matrix::displayData() {
    const uint32_t matrix_size = (this->column_size * this->row_size);
    for(uint32_t i = 0; i < matrix_size; ++i) {
        // TODO: define a configuration parameter for setw
        std::cout << std::setw(4) << data[i];
        if (((i + 1) % this->column_size) == 0U) {
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

Matrix Matrix::operator + (const Matrix& m) {
    assert(this->column_size == m.column_size);
    assert(this->row_size == m.row_size);
    Matrix result {m.column_size, m.row_size};
    const uint32_t matrix_size = (this->column_size * this->row_size);
    for(uint32_t i = 0; i < matrix_size; ++i) {
        result.data[i] = this->data[i] + m.data[i];
    }
    return result;
}

Matrix Matrix::operator - (const Matrix& m) {
    assert(this->column_size == m.column_size);
    assert(this->row_size == m.row_size);
    Matrix result {m.column_size, m.row_size};
    const uint32_t matrix_size = (this->column_size * this->row_size);
    for(uint32_t i = 0; i < matrix_size; ++i) {
        result.data[i] = this->data[i] - m.data[i];
    }
    return result;
}


#include "matrix.h"

Matrix::Matrix(const uint32_t column_size, const uint32_t row_size) : column_size(column_size), row_size(row_size) {
    const uint32_t matrix_size = (column_size * row_size);
    data.reserve(matrix_size);
    for(uint32_t i = 0U; i < matrix_size; ++i) {
        data[i] = i;
    }
}

const uint32_t Matrix::getColumnSize() {
    return column_size;  
}

const uint32_t Matrix::getRowSize() {
    return row_size;  
}

const std::vector<uint32_t> Matrix::getData() {
    return data;  
}

void Matrix::setValueByIndex(const uint32_t column_index, const uint32_t row_index, const uint32_t value) {
    data[((row_index - 1) * this->column_index) + (column_index - 1)] = value;
}

const uint32_t Matrix::getValueByIndex(const uint32_t column_index, const uint32_t row_index) {
    return data[((row_index - 1) * this->column_index) + (column_index - 1)];
}

void Matrix::displayData() {
    const uint32_t matrix_size = (this->column_size * this->row_size);
    for(uint32_t i = 0; i < matrix_size; ++i) {
        std::cout << data[i];
    }
    std::cout << std::endl;
}
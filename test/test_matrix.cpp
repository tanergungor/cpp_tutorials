#include <cstdint>

#include <gtest/gtest.h>

#include "matrix/matrix.h"

template class Matrix<int32_t>;

TEST(TestMatrix, MatrixCanHaveMinimumColumnAndRowSize) {
    const uint32_t column_size = 0U;
    const uint32_t row_size = 0U;
    Matrix<int32_t> matrix {column_size, row_size};
    EXPECT_EQ(matrix.getColumnSize(), column_size);
    EXPECT_EQ(matrix.getRowSize(), row_size);
}

TEST(TestMatrix, MatrixCanHavePositiveColumnAndRowSize) {
    const uint32_t column_size = 32U;
    const uint32_t row_size = 32U;
    Matrix<int32_t> matrix {column_size, row_size};
    EXPECT_EQ(matrix.getColumnSize(), column_size);
    EXPECT_EQ(matrix.getRowSize(), row_size);
}

TEST(TestMatrix, MatrixCanHaveMaximumColumnAndRowSize) {
    const uint32_t column_size = UINT32_MAX;
    const uint32_t row_size = UINT32_MAX;
    Matrix<int32_t> matrix {column_size, row_size};
    EXPECT_EQ(matrix.getColumnSize(), column_size);
    EXPECT_EQ(matrix.getRowSize(), row_size);
}

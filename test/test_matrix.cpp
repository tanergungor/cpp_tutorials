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

TEST(TestMatrix, MatrixCanCopyConstructor) {
    const uint32_t column_size = 3U;
    const uint32_t row_size = 3U;
    const std::vector<int32_t> data = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<int32_t> m_0 {column_size, row_size, data};
    Matrix<int32_t> m_1 = m_0;
    EXPECT_TRUE(m_1 == m_0);
    Matrix<int32_t> m_2(m_0);
    EXPECT_TRUE(m_2 == m_0);
}

TEST(TestMatrix, MatrixCanCopyAssignment) {
    const uint32_t column_size = 3U;
    const uint32_t row_size = 3U;
    const std::vector<int32_t> data_0 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    const std::vector<int32_t> data_1 = {2, 3, 4, 5, 6, 7, 8, 9, 1};
    Matrix<int32_t> m_0 {column_size, row_size, data_0};
    Matrix<int32_t> m_1 {column_size, row_size, data_1};
    m_1 = m_0;
    EXPECT_TRUE(m_1 == m_0);
}

TEST(TestMatrix, MatrixCanMoveConstructor) {
    const uint32_t column_size = 3U;
    const uint32_t row_size = 3U;
    const std::vector<int32_t> data_0 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<int32_t> m_0 {Matrix<int32_t>{column_size, row_size, data_0}};
    // TODO: check data
    EXPECT_EQ(m_0.getColumnSize(), column_size);
    EXPECT_EQ(m_0.getRowSize(), row_size);
}

TEST(TestMatrix, MatrixCanMoveAssignment) {
    const uint32_t column_size = 3U;
    const uint32_t row_size = 3U;
    const std::vector<int32_t> data_0 = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    Matrix<int32_t> m_0 {column_size, row_size, data_0};
    Matrix<int32_t> m_1 = m_0;
    // TODO: check data
    EXPECT_EQ(m_1.getColumnSize(), column_size);
    EXPECT_EQ(m_1.getRowSize(), row_size);
}

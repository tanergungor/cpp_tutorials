#include <gtest/gtest.h>

#include "matrix/matrix.h"

TEST(TestMatrix, MatrixCanHavePositiveSize) {
    const uint32_t column_size = 3U;
    const uint32_t row_size = 3U;
    Matrix matrix {column_size, row_size};
    EXPECT_EQ(matrix.getColumnSize(), column_size);
    EXPECT_EQ(matrix.getRowSize(), row_size);
}

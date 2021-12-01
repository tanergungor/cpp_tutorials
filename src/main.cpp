#include "hello_world/hello_world.h"
#include "matrix/matrix.h"

int main()
{
    hello_world();

    const uint32_t cols = 3U;
    const uint32_t rows = 3U;
    Matrix<int32_t> m_1 {cols, rows};
    Matrix<int32_t> m_2 (cols, rows);

    std::cout << "Matrix m_1 cols: " << m_1.getColumnSize() << std::endl;
    std::cout << "Matrix m_1 rows: " << m_1.getRowSize() << std::endl;
    std::cout << "Matrix m_1(3, 3): " << m_1.getValueByIndex(3, 3) << std::endl;
    m_1.setValueByIndex(0, 0, 1);
    m_1.setValueByIndex(0, 1, 2);
    m_1.setValueByIndex(0, 2, 3);
    m_1.setValueByIndex(1, 0, 1);
    m_1.setValueByIndex(1, 1, 1);
    m_1.setValueByIndex(1, 2, 1);
    m_1.setValueByIndex(2, 0, 1);
    m_1.setValueByIndex(2, 1, 1);
    m_1.setValueByIndex(2, 2, 2);
    std::cout << "Matrix m_1(3, 3): " << m_1.getValueByIndex(3, 3) << std::endl;

    m_2.setValueByIndex(0, 0, 1);
    m_2.setValueByIndex(0, 1, 2);
    m_2.setValueByIndex(0, 2, 3);
    m_2.setValueByIndex(1, 0, 1);
    m_2.setValueByIndex(1, 1, 1);
    m_2.setValueByIndex(1, 2, 1);
    m_2.setValueByIndex(2, 0, 1);
    m_2.setValueByIndex(2, 1, 1);
    m_2.setValueByIndex(2, 2, 9);

    std::cout << "m_1: " << std::endl;
    m_1.displayData();

    std::cout << "m_2: " << std::endl;
    m_2.displayData();

    std::cout << "m_3 = m_1 + m_2: " << std::endl;
    Matrix<int32_t> m_3 = m_1 + m_2;
    m_3.displayData();

    std::cout << "m_4 = m_1 - m_2: " << std::endl;
    Matrix<int32_t> m_4 = m_1 - m_2;
    m_4.displayData();

    std::cout << "m_1 = m_1 * m_2: " << std::endl;
    m_1.dotProduct(m_2);
    m_1.displayData();

    std::cout << "m_1 = m_1 / m_2: " << std::endl;
    m_1.dotQuotient(m_2);
    m_1.displayData();

    std::cout << "m_2: " << std::endl;
    m_2.displayData();

    std::cout << "Copy Constructor" << std::endl;
    std::cout << "m_5 = m_2: " << std::endl;
    Matrix<int32_t> m_5 = m_2;
    m_5.displayData();

    std::cout << "Copy Constructor" << std::endl;
    std::cout << "m_6(m_2): " << std::endl;
    Matrix<int32_t> m_6(m_2);
    m_6.displayData();

    std::cout << "Copy Assignment" << std::endl;
    std::cout << "m_6 = m_1: " << std::endl;
    m_6 = m_1;
    m_6.displayData();

    std::cout << "Move Constructor" << std::endl;
    std::cout << "m_7(Matrix<int32_t>()): " << std::endl;
    Matrix<int32_t> m_7(Matrix<int32_t>(cols, rows));
    m_7.displayData();

    std::cout << "Move Assignment" << std::endl;
    std::cout << "m_8 = m_7: " << std::endl;
    Matrix<int32_t> m_8 = m_7;
    m_8.displayData();
}

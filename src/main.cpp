#include "hello_world/hello_world.h"
#include "matrix/matrix.h"

int main()
{
    hello_world();

    uint32_t cols = 3U;
    uint32_t rows = 3U;
    Matrix m_1 {cols, rows};

    std::cout << "Matrix m_1 cols: " << m_1.getColumnSize() << std::endl;
    std::cout << "Matrix m_1 rows: " << m_1.getRowSize() << std::endl;
    // std::cout << "Matrix m_1 capacity: " << m_1.getData().capacity() << std::endl;
    std::cout << "Matrix m_1(3, 3): " << m_1.getValueByIndex(3, 3) << std::endl;
    m_1.setValueByIndex(3, 3, 3);
    std::cout << "Matrix m_1(3, 3): " << m_1.getValueByIndex(3, 3) << std::endl;
    m_1.displayData();
}

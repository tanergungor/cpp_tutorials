#include "hello_world/hello_world.h"
#include "matrix/matrix.h"

int main()
{
    hello_world();

    const uint32_t cols = 3U;
    const uint32_t rows = 3U;
    Matrix m_1 {cols, rows};
    Matrix m_2 (cols, rows);
    Matrix m_3 (cols, rows);

    std::cout << "Matrix m_1 cols: " << m_1.getColumnSize() << std::endl;
    std::cout << "Matrix m_1 rows: " << m_1.getRowSize() << std::endl;
    std::cout << "Matrix m_1(3, 3): " << m_1.getValueByIndex(3, 3) << std::endl;
    m_1.setValueByIndex(0, 0, 1);
    m_1.setValueByIndex(0, 1, 2);
    m_1.setValueByIndex(0, 2, 3);

    m_2.setValueByIndex(2, 2, 9);
    std::cout << "Matrix m_1(3, 3): " << m_1.getValueByIndex(3, 3) << std::endl;

    std::cout << "m_1: " << std::endl;
    m_1.displayData();

    std::cout << "m_2: " << std::endl;
    m_2.displayData();

    std::cout << "m_3 = m_1 + m_2: " << std::endl;
    m_3 = m_1 + m_2;
    m_3.displayData();


    
    //m_1 += m_2
    //std::cout << "m_1 = m_1 + m_2: " << std::endl;
    //m_1.displayData();
}

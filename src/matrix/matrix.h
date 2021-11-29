#include <iostream>
#include <vector>

// * private members of a class are accessible only from within other members of the 
// same class (or from their "friends").
// * protected members are accessible from other members of the same class (or from their
// "friends"), but also from members of their derived classes. The class member declared 
// as Protected are inaccessible outside the class but they can be accessed by any 
// subclass(derived class) of that class.
// * public members are accessible from anywhere where the object is visible.

class Matrix {

    private:
        uint32_t column_size;
        uint32_t row_size;
        std::vector<uint32_t> data;
        
    public:
        Matrix(const uint32_t column_size, const uint32_t row_size);
        const uint32_t getColumnSize();
        const uint32_t getRowSize();
        const std::vector<uint32_t> getData();
        void setValueByIndex(const uint32_t cols, const uint32_t rows, const uint32_t value);
        const uint32_t getValueByIndex(const uint32_t cols, const uint32_t rows);
        void displayData();
};

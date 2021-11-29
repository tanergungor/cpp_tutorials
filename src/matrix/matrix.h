#include <iostream>
#include <vector>

class Matrix {

    private:
        //! Column number of the matrix.
        uint32_t column_size;
        //! Row number of the matrix.
        uint32_t row_size;
        //! Data vector of the matrix.
        std::vector<uint32_t> data;
        
    public:
        Matrix(const uint32_t column_size, const uint32_t row_size);

        //! Returns the column number of the matrix.
        /*!
        \return The column number of the matrix.
        */
        const uint32_t getColumnSize();

        //! Returns the row number of the matrix.
        /*!
        \return The row number of the matrix.
        */
        const uint32_t getRowSize();

        //! Returns the data vetor of the matrix.
        /*!
        \return The data vetor of the matrix.
        */
        const std::vector<uint32_t> getData();

        //! Sets the valeu in the specified index.
        /*!
        \param column_index an integer column index.
        \param row_index an integer row index.
        \param value an integer value that is going to be set.
        */
        void setValueByIndex(const uint32_t column_index, const uint32_t row_index, const uint32_t value);

        //! Returns the value in the specified index.
        /*!
        \param column_index an integer column index.
        \param row_index an integer row index.
        \return The value in the specified index.
        */
        const uint32_t getValueByIndex(const uint32_t column_index, const uint32_t row_index);

        //! Displays the array content.
        void displayData();
};

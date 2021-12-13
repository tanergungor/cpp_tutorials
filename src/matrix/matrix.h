#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <vector>

template<class T>
class Matrix {

    private:
        //! Column number of the matrix.
        uint32_t column_size;
        //! Row number of the matrix.
        uint32_t row_size;
        //! Data vector of the matrix.
        std::vector<T> data;
        
    public:
        //! Constructors
        Matrix() = delete; 
        Matrix(const uint32_t column_size, const uint32_t row_size);
        // TODO: add a constructor which initialize the data vector with user specified value
        Matrix(const uint32_t column_size, const uint32_t row_size, const std::vector<T> data);
        //! Destructor
        ~Matrix();
        //! Copy Constructor
        Matrix(const Matrix& m);
        //! Copy Assignment
        Matrix<T>& operator=(const Matrix<T>& m);
        //! Move Constructor
        Matrix(Matrix<T>&& m);
        //! Move Assignment
        Matrix<T>& operator= (Matrix<T>&&);

        //! Returns the column number of the matrix.
        const uint32_t getColumnSize();

        //! Returns the row number of the matrix.
        const uint32_t getRowSize();

        //! Returns the data vector of the matrix.
        const std::vector<T> getData();

        //! Sets the value in the specified index of data.
        /*!
        \param column_index an integer column index.
        \param row_index an integer row index.
        \param value a template-typed value that is going to be set.
        */
        void setValueByIndex(const uint32_t column_index, const uint32_t row_index, const T value);

        //! Returns the value in the specified index of data.
        /*!
        \param column_index an integer column index.
        \param row_index an integer row index.
        \return The template-typed value in the specified index.
        */
        const T getValueByIndex(const uint32_t column_index, const uint32_t row_index);

        //! Displays the array content.
        void displayData();

        void dotProduct(const Matrix<T>& rhs);
        void dotQuotient(const Matrix<T>& rhs);
        
        //! Operator+ overloading
        Matrix<T> operator+(const Matrix<T>& rhs) const;
        //! Operator- overloading
        Matrix<T> operator-(const Matrix<T>& rhs) const;
        //! Operator== overloading
        bool operator==(const Matrix<T>& rhs) const;
};

#endif

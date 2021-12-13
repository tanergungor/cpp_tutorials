#ifndef SINGLETON_H
#define SINGLETON_H

#include <iostream>
#include <memory>

template<class T>
class Singleton {

    private:
        //! data of the singleton class.
        T data;

        //! Constructors
        Singleton();
        //! Copy Constructor
        Singleton(const Singleton& s) = delete;
        //! Copy Assignment
        Singleton<T>& operator=(const Singleton<T>& s) = delete;
        //! Move Constructor
        Singleton(Singleton<T>&& s) = delete;
        //! Move Assignment
        Singleton<T>& operator= (Singleton<T>&&) = delete;
        
    public:

        static Singleton<T>& getInstance();

        //! Returns the data of the singleton instance.
        const T getData();

        //! Sets the value in the specified index of data.
        /*!
        \param data a template-typed value that is going to be set.
        */
        void setData(const T data);
};

#endif

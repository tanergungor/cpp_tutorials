#include "singleton.h"

template class Singleton<int32_t>;

template<class T>
Singleton<T>::Singleton() {
}

template<class T>
Singleton<T>& Singleton<T>::getInstance() {
    static Singleton<T> instance;
    return instance;
}

template<class T>
const T Singleton<T>::getData() {
    return data;
}

template<class T>
void Singleton<T>::setData(const T data) {
    this->data = data;
}

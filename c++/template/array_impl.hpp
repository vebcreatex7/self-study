#include <cstddef>
#include <new>
#include <iostream>







template<class T>
Array<T>::Array(size_t size, const T& value) : size_(size), data_(new T[size_]) {
    for (size_t i = 0; i != size_; ++i)
        data_[i] = value;
}

template <class T>
Array<T>::Array(Array const& other) {
    /*
    data_ = new T[other.size_];
    size_ = other.size_;
    for (size_t i = 0; i != size_; i++)
        data_[i] = other.data_[i];
    */
    size_ = other.size_;
    data_ = (T*) new char [size_ * sizeof(T)];
    for (size_t i = 0; i != size_; i++)
        new (data_ + i) T(other.data_[i]);
}

template <typename T>
Array<T>::~Array() {
    for (size_t i = 0; i != size_; i++)
        data_[i].~T();
    delete [] (char*) data_;
}

template <typename T>
Array<T>& Array<T>::operator=(Array const& other) {
    /*
    if (data_ != other.data_) {
        this->~Array();
        data_ = new T[other.size_];
        size_ = other.size_;
        for (size_t i = 0; i != size_; i++)
            data_[i] = other.data_[i];
        
    }
    return *this;
    */

    if (data_ != other.data_) {
        this->~Array();
        size_ = other.size_;
        data_ = (T*) new char [size_ * sizeof(T)];
        for (size_t i = 0 ; i != size_; i++)
            new (data_ + i) T(other.data_[i]);
    }
    return *this;
}

template <typename T>

size_t Array<T>::size() const {
    return size_;
}

template <typename T>
T& Array<T>::operator[] (size_t i) {
    return data_[i];
}

template <typename T>
T const& Array<T>::operator[](size_t i) const {
    return data_[i];
}



template<class T>
void flatten(T const & array, std::ostream& out) {
		out << array << ' ';
}

template <class T>
void flatten(Array<T> const & array, std::ostream& out) {
	for (size_t i = 0; i != array.size(); i++)
        flatten(array[i], out);
}
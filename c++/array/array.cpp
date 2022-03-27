#include <cstddef>
#include <new>

template <typename T>
class Array
{
public:

    // Список операций:
    //
    Array() : data_(nullptr), size_(0) {}

    explicit Array(size_t size, const T& value = T());
    //   конструктор класса, который создает
    //   Array размера size, заполненный значениями
    //   value типа T. Считайте что у типа T есть
    //   конструктор, который можно вызвать без
    //   без параметров, либо он ему не нужен.
    //
    Array(const Array &);
    //   конструктор копирования, который создает
    //   копию параметра. Считайте, что для типа
    //   T определен оператор присваивания.
    //
    ~Array();
    //   деструктор, если он вам необходим.
    //
    Array& operator=(Array const &);
    //   оператор присваивания.
    //
    size_t size() const;
    //   возвращает размер массива (количество
    //                              элементов).
    //
    T& operator[](size_t);
    const T& operator[](size_t) const;
    //   две версии оператора доступа по индексу.

private:
    T* data_;
    size_t size_;
};

template <class T>
Array<T>::Array(size_t size, T const& value)
    /*
    : data_(new T[size]), size_(size) {
        for (size_t i = 0; i != size_; i++)
            data_[i] = value;
    }
    */
{   
    size_ = size;
    data_ = (T*) new char [size_ * sizeof(T)];
    for (size_t i = 0; i != size_; i++)
        new (data_ + i) T(value);

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


int main() {
    Array<int> ai(10, 0);
    ai[5] = 2;
    Array<int> ai1(ai);

    Array<int> ai2(20, 1);
    ai2 = ai1;

    Array<Array<int>> ai5(2, ai);

}
#include <cstddef>
#include <new>
#include <iostream>

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


#include "array_impl.hpp"



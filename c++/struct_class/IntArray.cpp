#include <iostream>


class IntArray {
public:

    explicit IntArray(size_t);
    IntArray(IntArray const&);
    ~IntArray();
    IntArray& operator = (IntArray const &);
    size_t get_size() const;
    int get (size_t) const;
    int& get (size_t);
    void resize(size_t);
    

private:
    void Swap(IntArray&);
    size_t size;
    int* data;
};


IntArray::IntArray(size_t n) : size(n), data(new int [size]) {}

IntArray::IntArray(IntArray const& other) : size(other.size), data(new int[size]) {
    for (size_t i = 0; i != size; ++i)
        data[i] = other.data[i];
}


IntArray::~IntArray() {
    delete [] data;
}

void IntArray::Swap(IntArray& a) {
    size_t const t1 = size;
    size = a.size;
    a.size = t1;

    int * const t2 = data;
    data = a.data;
    a.data = t2;
}



IntArray& IntArray::operator = (IntArray const & other) {
    if (this != &other)
        IntArray(other).Swap(*this);
    return *this;

}


size_t IntArray::get_size() const {
    return size;
}

int IntArray::get(size_t i) const {
    return data[i];
}


int& IntArray::get(size_t i) {
    return data[i];
}

void IntArray::resize(size_t nsize) {
    IntArray tmp(nsize);
    size_t n = nsize > size ? size : nsize;
    for (size_t i = 0; i != n; i++)
        tmp.data[i] = data[i];
    Swap(tmp);
}

int main() {
    
}
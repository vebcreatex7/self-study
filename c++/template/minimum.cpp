#include <cstddef>
#include <iostream>

template <typename T>
class Array
{
public:
	explicit Array(size_t size = 0, const T& value = T());
	Array(const Array& other);
	~Array();
	Array& operator=(Array other);
	void swap(Array &other);
	size_t size() const;
	T& operator[](size_t idx);
	const T& operator[](size_t idx) const;

private:
	size_t size_;
	T *data_;
};


template<class T>
bool less (T const & a, T const & b) {
    return a < b;
}

template<class T>
struct Greater {
    bool operator() (T const& a, T const& b) const {return b < a;}
};



template<class T, class comp>
T minimum(Array<T> const & arr, comp less) {
    T min = T(arr[0]);
    for (size_t i = 1; i != arr.size(); i++) {
        if (less(arr[i], min))
            min = arr[i];
    }
    return min;
}




template<class T>
void flatten(T const & arr, std::ostream& out) {
	for (size_t i = 0; i != arr.size(); i++)
		flatten(arr[i], out);
}

template <class T>
void flatten(Array<T> const & array, std::ostream& out) {
	for (size_t i = 0; i != array.size(); i++)
		out << array[i] << ' ';
}


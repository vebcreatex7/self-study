#include <iostream>



struct Dummy { };
typedef int type;


template<class T, class U>
struct SameType
{static const bool value = false;};

template <class T>
struct SameType<T, T>
{static const bool value = true;};




int main() {
    std::cout << SameType<int, int>::value << std::endl; // выведет 1, т. е. true
}
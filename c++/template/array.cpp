#include <cstddef>
#include <new>
#include <iostream>

#include "array.hpp"

int main() {
    Array<int> ints(2, 0);
    ints[0] = 10;
    ints[1] = 20;
    flatten(ints, std::cout);
    Array< Array<int> > array_of_ints(2, ints);
flatten(array_of_ints, std::cout);

}
#include "foobarzoo.hpp"
#include "count.hpp"
#include <iostream>

int main() {
    tmp t;
    t.a = 1;
    t.b = 2;
    std::cout << t;

    std::cout << foo() << ' ' << bar() << ' ' << zoo() << '\n';
}
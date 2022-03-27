#include <iostream>


extern int var;

int next(int start = 0) {
    static int i = 0;
    i++;
    return i;
}




int main() {
    int const j = 2;

    int var;
    var++;
    std::cout << next() << ' ' << next();
}
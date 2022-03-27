#include <iostream>
#include <string>
#include <typeinfo>
using namespace std;



int main() {
    int x = 1, y = 2;
    x = y, y = x;
    cout << x << ' ' << y;
}
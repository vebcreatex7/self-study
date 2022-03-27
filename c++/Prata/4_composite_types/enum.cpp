#include <iostream>


enum bits {
   one = 1,
   two = 2,
   four = 4,
   eight = 8
};
 using namespace std;

int main() {
    bits band = bits(6);
    int x = 5;
    int* p = (int*)0xb123450;
    nullptr == (char*)0 ? cout << "yes\n" : cout << "no\n";
    NULL == (char*)0 ? cout << "yes\n" : cout << "no\n";
    //cout << *p;
}
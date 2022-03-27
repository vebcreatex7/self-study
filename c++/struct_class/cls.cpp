#include <iostream>


struct CLs {
    CLs(char c, double d, int i)
        : c(c), d(d), i(i) {}

private:
    double d;
    int i;
    char c;
    
    
    
};

char& get_c(CLs& cls) {
    double* p = (double*)&cls;
    return *(char*)p;
}

double& get_d(CLs& cls) {
    double* p = (double*)&cls;
    p += 1;
    return *p;
}

int& get_i(CLs& cls) {
    double* p = (double*)&cls;
    p += 2;
    return *(int*)p;
    
}

int main() {
    CLs a('c', 2.28, 5);
    double* p1 = (double*)&a;
    int* p2 = (int*)(p1 + 1);
    char* p3 = (char*)(p2 + 1);

    int const arr[3] = {1, 2, 3};
    int* z = (int*)&arr[1];
    *z  = 5;
    for (auto c : arr) {
        std::cout << c << ' ';
    }


    
    //std::cout << *p1 << ' ' << *p2 << ' ' << *p3;
}
#include <iostream>

template <class T>
class Auto_Ptr1 {
private:
    Auto_Ptr1(Auto_Ptr1 const &);
    T& operator = (Auto_Ptr1 const &);
    T* ptr_;

public:
    Auto_Ptr1(T* ptr = nullptr);
    ~Auto_Ptr1();
    T& operator* ();
    T* operator-> ();
};

template <class T>
Auto_Ptr1<T>::Auto_Ptr1(T* ptr) : ptr_(ptr) {}

template <class T>
Auto_Ptr1<T>::~Auto_Ptr1() {
    delete ptr_;
}

template <class T>
T& Auto_Ptr1<T>::operator* () {
    return *ptr_;
}

template <class T>
T* Auto_Ptr1<T>::operator-> () {
    return ptr_;
}



class Item {
public:
    Item() {
        std::cout << "Created";
    }
    ~Item() {
        std::cout << "Destroyed";
    }
};


int main() {
    Item* i1 = new Item;
    Auto_Ptr1<Item> p1 = i1;

    Auto_Ptr1<Item> p2 = new Item;

    double* d1 = new double(5);
    Auto_Ptr1<double> p3(d1);
    Auto_Ptr1<double> p4 = new double(3);

    *p3 = 22;

    std::cout << *p3 << ' ' << *p4;
}


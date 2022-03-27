#include <iostream>

template<class T>
struct SharedPtr
{
public:

    // реализуйте следующие методы
    //
    explicit SharedPtr(T *ptr = 0);
    ~SharedPtr();
    SharedPtr(const SharedPtr &);
    SharedPtr& operator=(const SharedPtr &);
    T* get() const;
    void reset(T *ptr = 0);
    T& operator*() const {
        return *ptr_;
    }
    T* operator->() const {
        return ptr_;
    }

private:
    T* ptr_;
    int* i;
};

template <class T>
SharedPtr<T>::SharedPtr(T *ptr) {
    ptr_ = ptr;
    i = nullptr;
    if (ptr_)
        i = new int(1);
}


template <class T>
SharedPtr<T>::~SharedPtr() {
    if (i and (--*i) == 0) {
        delete ptr_;
        delete i;
    }
}




template <class T>
SharedPtr<T>::SharedPtr(const SharedPtr & other) {
    if (other.i) {
        ptr_ = other.ptr_;
        i = other.i;
        ++*i;
    }
}



template <class T>
SharedPtr<T>& SharedPtr<T>::operator= (SharedPtr const& other) {
    if (ptr_ != other.ptr_) {
        if (i)
            this->~SharedPtr();
        if (other.i) {
            ptr_ = other.ptr_;
            i = other.i;
            ++*i;
        } else {
            ptr_ = nullptr;
            i = nullptr;
        }
        return *this;
    }
}



template <class T>
T* SharedPtr<T>::get() const {
    return ptr_;
}


template <class T>
void SharedPtr<T>::reset(T *ptr) {
    if (i)
        this->~SharedPtr();
    ptr_ = ptr;
    i = nullptr;
    if (ptr_)
        i = new int(1);

}





int main() {
    SharedPtr<double> p1;
    {


           
        SharedPtr<double> p2(new double(2));
        SharedPtr<double> p3(new double(3));
        SharedPtr<double> p4(p2);
        SharedPtr<double> p5;
        
        p5 = p2;
        p5 = p4;
        p1 = p5;
        p3.reset(NULL);
        p3 = p5;
        p5.reset(NULL);
        
        SharedPtr<double> p6;
        SharedPtr<double> p7;
        p7 = p7;
        
        p7.reset(NULL);
        p7.reset(new double(7));
        
        
    }
}

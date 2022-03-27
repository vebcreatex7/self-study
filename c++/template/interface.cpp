#include <iostream>
#include <memory>
using namespace std;

struct ICloneable
{
	virtual ICloneable* clone() const = 0;
	virtual ~ICloneable() { }
};

// Шаблон ValueHolder с типовым параметром T,
// должен содержать одно открытое поле data_
// типа T.
//
// В шаблоне ValueHolder должен быть определен
// конструктор от одного параметра типа T,
// который инициализирует поле data_.
//
// Шаблон ValueHolder должен реализовывать
// интерфейс ICloneable, и возвращать указатель
// на копию объекта, созданную в куче, из метода
// clone.

template <typename T>
struct ValueHolder : ICloneable {
    T data_;
    ValueHolder (T const & data) : data_(data) {}
    ValueHolder* clone() const override {
        return new ValueHolder (*this);
    }
};




class Any {
public:


    Any() : ptr_(nullptr) {}

    ~Any() {delete ptr_;}

    template<class T>
    Any(T const & value) : ptr_(new ValueHolder<T>(value)) {}
    

    Any(Any const& other) : ptr_ (other.ptr_ ? other.ptr_->clone() : nullptr) {}


    template <class T>
    Any& operator= (T const& value) {
        this->~Any();
        ptr_ = new ValueHolder<T>(value);
        return *this;
    }

    Any& operator= (Any const& other) {
        if (ptr_ != other.ptr_) {
            this->~Any();
            if (other.ptr_) {
               ptr_ = other.ptr_->clone();
            
            } else {
                ptr_ = nullptr;
            }
            
        }
        return *this;
    }
 

    



    template<class T>
    T* cast() const {
        ValueHolder<T>* val = dynamic_cast<ValueHolder<T>*> (ptr_);
        if (!this->ptr_)
            return nullptr;
        if (val) 
            return &val->data_;
        else 
            return nullptr;
    }


private:
    ICloneable* ptr_;
};


int main() {
    
}
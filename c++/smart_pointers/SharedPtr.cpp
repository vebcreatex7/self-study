struct Expression
{  
    virtual double evaluate() const = 0;
    virtual ~Expression() {};
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}
    double evaluate() const override {
        return value;
    }
    ~Number() {}

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), op(op), right(right)
    { }
    
    double evaluate() const override {
        switch(op) {
        case '+':
            return left->evaluate() + right->evaluate();
        case '-':
            return left->evaluate() - right->evaluate();
        case '*':
            return left->evaluate() * right->evaluate();
        case '/':
            return left->evaluate() / right->evaluate();
        }
        return 0;
    }
    
    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};





struct SharedPtr
{
public:

    // реализуйте следующие методы
    //
    explicit SharedPtr(Expression *ptr = 0);
    ~SharedPtr();
    SharedPtr(const SharedPtr &);
    SharedPtr& operator=(const SharedPtr &);
    Expression* get() const;
    void reset(Expression *ptr = 0);
    Expression& operator*() const {
        return *ptr_;
    }
    Expression* operator->() const {
        return ptr_;
    }

private:
    Expression* ptr_;
    int* i;
};


SharedPtr::SharedPtr(Expression *ptr) {
    ptr_ = ptr;
    i = nullptr;
    if (ptr_)
        i = new int(1);
}


SharedPtr::~SharedPtr() {
    if (i and (--*i) == 0) delete ptr_, delete i;
}




SharedPtr::SharedPtr(const SharedPtr & other) {
    if (other.i) {
        ptr_ = other.ptr_;
        i = other.i;
        *i++;
    }
}



SharedPtr& SharedPtr::operator= (SharedPtr const& other) {
    if (ptr_ != other.ptr_) {
        if (i)
            this->~SharedPtr();
        if (other.i) {
            ptr_ = other.ptr_;
            i = other.i;
            *i++;
        } else {
            ptr_ = nullptr;
            i = nullptr;
        }
    }
}



Expression* SharedPtr::get() const {
    return ptr_;
}


void SharedPtr::reset(Expression *ptr) {
    if (i)
        this->~SharedPtr();
    *this = SharedPtr(ptr);

}



int main() {
    SharedPtr p1;
{
    SharedPtr p2(new Expression("expr1"));
    SharedPtr p3(new Expression("expr2"));
    SharedPtr p4(p2);
    SharedPtr p5;
    p5 = p2;
    p5 = p4;
    p1 = p5;
    p3.reset(NULL);
    p3 = p5;
    p5.reset(NULL);
    SharedPtr p6;
    SharedPtr p7;
    p7 = p7;
    p7.reset(NULL);
    p7.reset(new Expression("expr3"));
    SharedPtr p8(new Expression("expr4"));
    p8.reset(NULL);
}
p1 = p1;
}





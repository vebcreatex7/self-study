#include <string>
#include <iostream>

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


struct Person {
    virtual ~Person() {}
    virtual std::string occupation() = 0;
};

struct Teacher : Person {
    std::string occupation () override {
        return "Teacher";
    }
    virtual std::string course() {
        return "dramma";
    }
};


struct Professor : Teacher {
    std::string occupation () override {
        return "Professor";
    }
    virtual std::string thesis() {
        return "qwer";
    }
};

int main() {
    //Expression * sube = new BinaryOperation(new Number(4.5), '*', new Number(5));
    Professor* p = new Professor;
    p->occupation();
    p->thesis();
    p->course();
    delete p;
}
#include <iostream>
#include <string>

using namespace std;

class Person {
public:
    Person(string name, int age)
        : name_(name), age_(age) {}

    string name() const {return name_;}
    int age() const {return age_;}

private:
    string name_;
    int age_;
};


class Student : public Person {
public:
    Student(string name, int age, string uni)
        : Person(name, age), uni_(uni) {}

    string university() const {return uni_;}
private:
    string uni_;
};


//void foo (int i) {std::cout << i + 1 << "int" << std::endl;}
void foo(char c) { std::cout << c <<  "char" << std::endl; }
//void foo(signed char) { std::cout << "signed char" << std::endl; }
//void foo(unsigned char) { std::cout << "unsigned char" << std::endl; }

int main() {
    
    foo(99);
}




#include <cstddef>
#include <cstring>
#include <iostream>




struct String {
    size_t size;
    char* str;

    String(const char* str = "") : size(strlen(str)), str(new char [size + 1]) {
        strcpy(this->str, str);
        this->str[size] = '\n';
    }


    String(size_t n) : size(n), str(new char [size + 1]) {

        str[size] = '\0';
    }

    String(String const & other)
        : size(other.size), str(new char [size + 1]) {
            for (size_t i = 0; i != size; ++i)
                str[i] = other.str[i];
            str[size] = '\0';
    }

    String& operator = (String const & str) {
        if (this != &str) {
            delete [] this->str;
            size = str.size;
            this->str = new char [size + 1];
            for (size_t i = 0; i != size; ++i)
                this->str[i] = str.str[i];
            this->str[size] = '\0';
        }
        return *this;
    }
    
        


    ~String() {
        delete [] str;
    }

    void append(String& other) {
        char* tmp = new char [this->size + other.size + 1];
        size_t i = 0;
        for (i; i != this->size; ++i)
            tmp[i] = this->str[i];
        for (size_t j = 0; j < other.size; j++) {
            tmp[i + j] = other.str[j];
        }
        this->size += other.size;
        tmp[this->size] = '\0';
        delete [] this->str;
        this->str = tmp;
    }

    struct Segment {

    Segment(String const & s, size_t begin) {

        size = s.size - begin;
        this->begin = begin;
        this->str = new char [size + 1];
        for (size_t i = 0; i != size; i++)
            this->str[i] = s.str[i + begin];
        this->str[size] = '\0';
    }
    ~Segment() {
        delete [] str;
    }


    String operator [] (size_t j) {
        size_t n = j - begin;
        String ans(n);
        for (size_t i = 0; i != n; i++)
            ans.str[i] = this->str[i];
        return ans;  
    }
    
private:
    
    char* str;
    size_t size;
    size_t begin;
};


    Segment operator [] (size_t i) const {
        return Segment(*this, i);
    }



    
    friend std::ostream& operator << (std::ostream& os, String const & s);
    
};

void foo (String str) {
    std::cout << str.str;
}


std::ostream& operator << (std::ostream& os, String const & s) {
    for (size_t i = 0 ; i != s.size; i++)
        os << s.str[i];
    return os;
}


int main() {
    String a("qwerty");
    String c = String("qwrtg");
    //a.Make_Segment(1);
    String d = a[1][2];
    std::cout  << d;
    
}


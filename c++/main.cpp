#include "square.hpp"
#include <iostream>



char *resize(const char *str, unsigned size, unsigned new_size)
{
	char* newStr = new char[new_size];
    size_t i = 0;
    for (; i <  new_size and i < size; i++) {
        newStr[i] = str[i];
    }
    delete [] str;
    return newStr;
}


char *getline() {
    size_t size = 10;
    char* stream = new char[size];
    char c;
    size_t i = 0;
    while(std::cin.get(c) and c != '\n') {
        stream[i] = c;
        i++;
        if (i > size / 2) {
            size *= 2;
            char* newStream = new char[size];
            size_t j = 0;
            for (; j <= i; j++)
                newStream[j] = stream[j];
            delete [] stream;
            stream = newStream;
        }
    }
    stream[i] = '\0';
    return stream;

}




int main() {
    
    
    char* c = getline();
    std::cout << c;
    delete [] c;

     
}
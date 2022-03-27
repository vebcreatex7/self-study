#include <cstddef> // size_t
#include <string.h>


struct String;

struct Segment {
    Segment(char const * str, size_t begin) {

        size = strlen(str) - begin;
        this->begin = begin;
        this->str = new char [size + 1];
        for (size_t i = 0; i != size; i++)
            this->str[i] = str[i + begin];
        this->str[size] = '\0';
    }
    ~Segment() {
        delete [] str;
    }

    String operator [] (size_t j) {
        char * tmp = new char[j - begin];
        for (size_t i = begin; i != j; i++)
            tmp[i] = str[i];
        String ans(tmp);
        delete [] tmp;
        return ans;
    }

private:
    char* str;
    size_t size;
    size_t begin;
};

struct String {
	String(const char *str = "");
	String(size_t n, char c);
	~String();

    String(const String &other);
    String &operator=(const String &other);

	void append(const String &other);

    Segment operator [] (size_t i) const {
        return Segment(str, i);
    }

	size_t size;
	char *str;
};
#include <iostream>

struct tmp {
    friend std::ostream& operator << (std::ostream& os, tmp const& t);
    
    int a, b;

};

inline std::ostream& operator << (std::ostream& os, tmp const& t) {
    os << t.a << ' ' << t.b << '\n';
    return os;
}


inline int count() {
    static int counter = 0;
    return ++counter;
}
#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t n;
    cin >> n;
    uint64_t sum = 0;
    while(n--) {
        uint64_t tmp = 0;
        cin >> tmp;
        sum += tmp;
    }
    cout << sum;
}
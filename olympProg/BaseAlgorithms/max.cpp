#include <bits/stdc++.h>

using namespace std;

int main() {
    size_t n = 0;
    cin >> n;
    size_t pos_max = 0;
    int max = INT_MIN;
    for (size_t i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        if (tmp > max) {
            max = tmp;
            pos_max = i + 1;
        }
    }
    cout << pos_max << '\n';
}
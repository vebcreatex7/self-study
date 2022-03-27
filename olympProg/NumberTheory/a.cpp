#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int main() {
    fast;
    int a, b, c;
    cin >> a >> b >> c;
    int d = 1 / (1. / c + 1. / a + 1. / b);
    cout << d;
    return 0;
}

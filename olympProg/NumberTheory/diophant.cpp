#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {
    fast;
    int a, b, c;
    cin >> a >> b >> c;

    c % gcd(abs(a), abs(b)) == 0 ? cout << "1\n" : cout << "0\n";

    return 0;
}

#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;


ull gcd (ull a, ull b) {
    return b == 0 ? a : gcd(b, a % b);
}

ull myPow (ull a, ull p) {
    if (p == 0)
        return 1;
    else {
        if (p % 2 == 0)
            return myPow(a, p / 2) * myPow(a, p / 2);
        else
            return myPow(a, p - 1) * a;
    }
}
int main() {
    fast;
    ull a, b;
    cin >> a >> b;

    ull g = gcd(a, b);

    if (myPow(10, 18) / a < b / g)
        cout << "-1\n";
    else
        cout << a * b / g << endl;

    return 0;
}

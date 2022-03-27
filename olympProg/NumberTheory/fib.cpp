#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

ll const MOD = (ll)1e6 + 3;

ll Norm(ll a) {
    return ((a % MOD) + MOD) % MOD;
}

ll Nadd(ll a, ll b) {
    return Norm(Norm(a) + Norm(b));
}

int main() {
    fast;
    ll n;
    cin >> n;
    ll fib1, fib2, fib3;
    fib1 = fib2 = 1;

    if (n < 2) {
        cout << "1\n";
    } else {
        ll i = 2;
        while (i <= n) {
            fib3 = Nadd(fib1, fib2);
            fib1 = fib2;
            fib2 = fib3;
            i++;
        }
        cout << fib3 << endl;
    }

    return 0;
}

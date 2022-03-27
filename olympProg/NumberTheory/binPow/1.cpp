#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long



using namespace std;

ll Mod(ll a, ll mod) {
    return(a % mod + mod) % mod;
}

ll Mmul (ll a, ll b, ll mod) {
    return Mod(Mod(a, mod) * Mod(b, mod), mod);
}

ll MfastPow(ll a, ll n, ll mod) {
    if (n == 0LL) return 1;
    if (n % 2 == 1) return Mmul(a, MfastPow(a, n - 1, mod), mod);
    ll tmp = MfastPow(a, n / 2, mod);
    return Mmul(tmp, tmp, mod);
}

int main() {
    fast;
    ll n, m;
    cin >> n >> m;
    cout << MfastPow(n, n, m) << endl;
    return 0;
}

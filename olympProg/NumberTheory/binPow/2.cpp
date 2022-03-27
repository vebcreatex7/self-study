#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

ll const mod = (ll)(1e9) + 7LL;

ll Mod(ll a, ll mod) {
    return(a % mod + mod) % mod;
}

ll Mmul(ll a, ll b, ll mod) {
    return Mod(Mod(a, mod) * Mod(b, mod), mod);
}

ll Madd(ll a, ll b, ll mod) {
    return Mod(Mod(a, mod) + Mod(b, mod), mod);
}



ll MfastPow(ll a, ll n, ll mod) {
    if (n == 0LL) return 1LL;
    if (n % 2 == 1) return Mmul(a, MfastPow(a, n - 1, mod), mod);
    ll tmp = MfastPow(a, n / 2, mod);
    return Mmul(tmp, tmp, mod);
}


ll Mdiv(ll a, ll b, ll mod) {
    return Mmul(a, MfastPow(b, mod - 2, mod), mod);
}

int main() {
    fast;
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    ll numerator = Madd(Mmul(a, d, mod), Mmul(b, c, mod), mod);
    ll ans = Mdiv(numerator, b, mod);
    ans = Mdiv(ans, d, mod);
    cout << ans <<endl;
    return 0;
}

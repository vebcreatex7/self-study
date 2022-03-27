#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

ll Mod(ll a, ll mod) {
    return ((a % mod) + mod) % mod;
}

ll Mmul(ll a, ll b, ll mod) {
    return Mod(Mod(a, mod) * Mod(b, mod), mod);
}

ll Madd(ll a, ll b, ll mod) {
    return Mod(Mod(a, mod) + Mod(b, mod), mod);
}




ll extgcd(ll a, ll b, ll& x, ll& y) {
    if (a == 0LL) {
        x = 0LL, y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = extgcd(b % a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll Mdiv(ll a, ll b, ll mod) {
    ll x, y;
    ll g = extgcd(b, mod, x, y);
    if (g != 1LL) return -1LL;
    return Mmul(a, x, mod);
}

ll reverseElem(ll a, ll mod) {
    
    ll x, y;
    ll g = extgcd(a, mod, x, y);
    if (g != 1LL) return -1LL;
    else return Mod(x, mod);
}


int main() {
    fast;
    ll a, n, m;
    cin >> a >> n >> m;
    
    ll ans = 0LL;
    ll rev = reverseElem(a, m);
    ll denumerator = a;
    if (rev == -1LL) {
        cout << -1 << endl;
        return 0;
    }
    for (ll i = 1LL; i <= n; i++) {
        ans = Madd(ans, Mdiv(i, denumerator, m), m);
        //ans = Madd(ans, Mmul(i, rev, m), m);
        denumerator = Mmul(denumerator, a, m);
        //rev = reverseElem(denumerator, m);
    }
    cout << Mod(ans, m);
    cout << endl;
    return 0;
}

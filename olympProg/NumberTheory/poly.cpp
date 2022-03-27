#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

ll Norm(ll a, ll MOD) {
    return ((a % MOD) + MOD) % MOD;
}

ll Nadd(ll a, ll b, ll MOD) {
    return Norm(Norm(a, MOD) + Norm(b, MOD), MOD);
}

ll Nmul(ll a, ll b, ll MOD) {
    return Norm(Norm(a, MOD) * Norm(b, MOD), MOD);
}



int main() {
    fast;
    ll n, m;
    cin >> n >> m;
    vector<ll> a(n + 1);
    for (auto& c : a)
        cin >> c;

    ll ans = -1;
    for (ll i = 0; i <= m; i++) {
        
        vector<ll> x(n + 1);
        x[0] = 1;
        for (size_t j = 1; j != n + 1; j++)
            x[j] = Norm(x[j - 1] * i, m);


        ll f_x = 0;
        for (ll p = 0; p <= n; p++) {
            f_x = Nadd(f_x, a[p] * x[n - p], m);
        }
        if (f_x % m == 0) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;
    

    return 0;
}

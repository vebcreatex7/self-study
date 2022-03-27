#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

ll Norm(ll a, ll MOD) {
    return ((a % MOD) + MOD) % MOD;
}

ll Nmul(ll a, ll b, ll MOD) {
    return Norm(Norm(a, MOD) * Norm(b, MOD), MOD);
}

ll Nsub(ll a, ll b, ll MOD) {
    return Norm(Norm(a, MOD) - Norm(b, MOD), MOD);
}

void solve() {
    ll const MOD = (ll)1e6 + 7;
    ll a, b;
    cin >> a >> b;

    cout << Nsub(Nmul(a, a, MOD), Nmul(b, b, MOD), MOD) << endl;
}

int main() {
    fast;
    solve();
    return 0;
}

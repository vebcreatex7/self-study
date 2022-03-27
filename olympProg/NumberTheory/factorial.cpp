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


void solve() {
    ll const MOD = (ll)1e6 + 3;
    ll n;
    cin >> n;
    if (n < 2)
        cout << "1\n";
    
    else if (n >= MOD) 
        cout << "0\n";
    else  {
        ll i = 1;
        ll ans = 1;
        while (i < n) {
            i++;
            ans = Nmul(ans, i, MOD);
        }
        cout << ans << endl;
    }
}

int main() {
    fast;
    solve();
    return 0;
}

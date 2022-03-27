#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

ll Mod(ll a, ll mod) {
    return (a % mod + mod) % mod;
}

ll Madd(ll a, ll b, ll mod) {
    return Mod(Mod(a, mod) + Mod(b, mod), mod);
} 

ll Msub (ll a, ll b, ll mod) {
    return Mod(Mod(a, mod) - Mod(b, mod), mod);
}

int main() {
    const ll mod = (ull)1e9 + 7;
    fast;
    int n;
    int k;
    cin >> n >> k;
    string a;
    cin >> a;
    vector<ll> dp(n + 1);
    dp[0] = 1ll;
    dp[1] = 1ll - (a[0] - '0');
    ll s = dp[0] + dp[1];
    for (int i = 2; i <= k; i++) {
        if (a[i - 1] != '1') {
            dp[i] = s;
        } else {
            dp[i] = 0ll;
        }
        s = Madd(s, dp[i], mod);
    }
    s = Msub(s, 1ll, mod);
    for (int i = k + 1; i <= n; i++) {
        if (a[i - 1] != '1') {
            dp[i] = s;
        } else {
            dp[i] = 0ll;
        }
        s = Msub(Madd(s, dp[i], mod), dp[i - k], mod);
    }


    
   cout << Mod(dp[n], mod) << endl;

    
}

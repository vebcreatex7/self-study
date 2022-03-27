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

ll Mmul(ll a, ll b, ll mod) {
    return Mod(Mod(a, mod) * Mod(b, mod), mod);
}

int main() {
    fast;
    ll mod = static_cast<ll>(1e9 + 33);
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0ll));
    vector<ll> s(m + 1, 0ll);
    dp[1][1] = 1ll;
    s[1] = 1;

    if (n > 1) {
        dp[2][1] = 1;
        for (int i = 3; i <= n; i++)
            dp[i][1] = Mmul(2ll, dp[i - 1][1], mod);
    }
    if (m > 1) {
        dp[1][2] = 1;
        s[2] = 1;
        for (int j = 3; j <= m; j++) {
            dp[1][j] = Mmul(2ll, dp[1][j - 1], mod);
            s[j] = dp[1][j];
        }
    }

    for (int i = 2; i <= n; i++) {
        ll tmp = dp[i][1];
        for (int j = 2; j <= m; j++) {
            dp[i][j] = Madd(tmp, s[j], mod);
            s[j] = Madd(s[j], dp[i][j], mod);
            tmp = Madd(tmp, dp[i][j], mod);
        }
    }

    

    cout << dp[n][m] << endl;
    return 0;
}

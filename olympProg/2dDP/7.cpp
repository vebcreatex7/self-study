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
    int n, m;
    cin >> n >> m;
    ll mod{static_cast<ll>(1e9 + 7)};
    vector<vector<ll>> dp(n + 1, vector<ll>(m + 1, 0ll));
    dp[1][1] = 1;
    if (m > 1) {
        for (int i = 2; i <= m; i++) {
            dp[1][i] = Mmul(2ll, dp[1][i - 1], mod);
        }
    }
    if (n > 1) {
        for (int i = 2; i <= n; i++) {
            dp[i][1] = Mmul(2ll, dp[i - 1][1], mod);
        }
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= m; j++) {
            dp[i][j] = Mod(2 * dp[i - 1][j] + 2 * dp[i][j - 1] - 2 * dp[i - 2][j - 1] - 2 * dp[i - 1][j - 2] - dp[i - 2][j] - dp[i - 2][j - 2] - dp[i][j - 2], mod);
        }
    }

    for (auto a1 : dp) {
        for (auto a2 : a1)
            cout << a2 << ' ';
        cout << endl;
    }


    ll ans = dp[n][m] - dp[n - 1][m] - dp[n][m - 1] - dp[n - 1][m - 1];
    cout << ans;
    return 0;
}

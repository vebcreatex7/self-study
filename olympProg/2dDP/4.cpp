#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

ll Mod(ll a, ll mod) {
    return (a % mod + mod) % mod;
}

ll Madd(ll a, ll b, ll c, ll mod) {
    return Mod(Mod(Mod(a, mod) + Mod(b, mod), mod) + Mod(c, mod), mod);
}

int main() {
    fast;

    ll mod = static_cast<ll>(1e9 + 9);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for (auto& a1 : a) {
        for (auto& a2 : a1)
            cin >> a2;
    }

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0ll));
    dp[0][0] = 1ll;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i - 1][j - 1] == 1)
                dp[i][j] = 0;
            else 
                dp[i][j] = Madd(dp[i - 1][j], dp[i - 1][j - 1], dp[i][j - 1], mod);
        }
    }

    

    cout << dp[n][m] << endl;
    return 0;
}

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




int n, m;
ll mod = static_cast<ll>(1e9 + 123);
ll dp[1001][1001];



ll DP (int i, int j) {
    if (i == 0 and j == 0) {
        return dp[0][0] = 1ll;
    }else if (i < 0 or j < 0 or i >= n or j >= m) {
        return 0;
    } else {
        if (dp[i][j])
            return dp[i][j];
        else 
            return dp[i][j] = Madd(Madd(DP(i - 2, j - 1), DP(i - 1, j - 2), mod), Madd(DP(i - 2, j + 1), DP(i + 1, j - 2), mod), mod);
    }
}



int main() {
    fast;
    cin >> n >> m;
    ll ans = DP(n - 1, m - 1);
    cout << ans << endl;
    
    

    return 0;
}
#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int main() {
    fast;
    int m, n;
    cin >> m >> n;
    
    vector<vector<int>> h(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> h[i][j];
        }
    }

      

    vector<vector<int>> dp(n, vector<int>(m));

    dp[0][0] = 0;

    for (int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i - 1] + abs(h[0][i] - h[0][i - 1]);
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + abs(h[i][0] - h[i - 1][0]);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(dp[i - 1][j] + abs(h[i][j] - h[i - 1][j]), dp[i][j - 1] + abs(h[i][j] - h[i][j - 1]));
        }
    }


    

    cout << dp[n - 1][m - 1] << endl;

    

    return 0;
}

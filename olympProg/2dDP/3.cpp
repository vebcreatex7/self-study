#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int main() {
    fast;
    int n;
    cin >> n;
    vector<vector<int>> a(n,vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = a[0][0];

    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + a[i][j];
            else if (j == i)
                dp[i][i] = dp[i - 1][i - 1] + a[i][i];
            else 
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
        }
    }

    cout << *max_element(dp[n - 1].begin(), dp[n - 1].end());
    return 0;
}

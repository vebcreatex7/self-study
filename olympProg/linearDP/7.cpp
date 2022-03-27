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

    if (n == 0) {
        cout << "1\n";
        return 0;
    }

    ull dp[n];
    dp[0] = 3;
    dp[1] = 8;
    for (int i = 2; i < n; i++) {
        dp[i] = dp[i - 2] * 2 + (dp[i - 1] - dp[i - 2]) * 3;
    }
    cout << dp[n - 1] << endl;
    return 0;
}

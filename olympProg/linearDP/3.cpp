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
    int* dp = new int [n + 1];
    dp[0] = 0;
    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        if (i % 2 == 0 and i % 3 == 0) 
            dp[i] = min(min(dp[i - 1], dp[i / 2]), dp[i / 3]) + 1;
        else if (i % 2 == 0)
            dp[i] = min(dp[i - 1], dp[i / 2]) + 1;
        else if (i % 3 == 0)
            dp[i] = min(dp[i - 1], dp[i / 3]) + 1;
        else
            dp[i] = dp[i - 1] + 1;
    }
    cout << dp[n] << endl;



    delete [] dp;
    return 0;
}

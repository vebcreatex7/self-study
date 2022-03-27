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
    ll* dp = new ll[n + 1];
    ll* a = new ll[n];

    for (int i = 0; i != n; i++) 
        cin >> a[i];

    dp[0] = 0ll;
    dp[1] = a[0];

    for (int i = 2; i <= n; i++) {
        if (i < 3) 
            dp[i] = dp[i - 1] + a[i - 1];
        else if (i < 5)
            dp[i] = max(dp[i - 1], dp[i - 3]) + a[i - 1];
        else 
            dp[i] = max(max(dp[i - 1], dp[i - 3]), dp[i - 5]) + a[i - 1];
    }

    cout << dp[n];





   delete [] dp;
   delete [] a;
    return 0;
}

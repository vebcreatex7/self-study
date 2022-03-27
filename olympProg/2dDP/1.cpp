#include <bits/stdc++.h>
#include <iterator>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> field(n, vector<int>(m));
    for (std::vector<std::vector<int>>::iterator it1 = field.begin(); it1 != field.end(); it1++) {
        for (std::vector<int>::iterator it2 = it1->begin(); it2 != it1->end(); it2++) {
            cin >> *it2;
        }
    }

    

    vector<vector<int>> dp(n, vector<int>(m));

    dp[0][0] = field[0][0]; 

    for (int i = 1; i < m; i++) {
        dp[0][i] = dp[0][i - 1] + field[0][i];
    }

    for (int i = 1; i < n; i++) {
        dp[i][0] = dp[i - 1][0] + field[i][0];
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            dp[i][j] = min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]) + field[i][j];
        }
    }

    cout << dp[n - 1][m - 1] << endl;



    return 0;
}

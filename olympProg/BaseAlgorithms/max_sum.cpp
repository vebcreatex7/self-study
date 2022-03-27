#include <bits/stdc++.h>

using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &a : v)
        cin >> a;

    int64_t ans = v[0], sum = 0;
    for (size_t i = 0; i < n; ++i) {
        sum += v[i];
        ans = max(ans, sum);
        sum = max(sum, int64_t(0));
    }
    cout << ans << '\n';

    

}
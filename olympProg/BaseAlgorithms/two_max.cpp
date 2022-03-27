#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long

ll const MOD = 1791791791;



using namespace std;

int main() {
    fast;
    
    int n;
    cin >> n;
    ll cur, a, b;
    cin >> cur >> a >> b;
    ll max1 = LONG_LONG_MIN, max2 = LONG_LONG_MIN;
    ll i1 = -1, i2 = -1;
    for (size_t i = 0; i != n; i++) {
        cur = (cur * a + b) % MOD;
        if (cur > max1) {
            max2 = max1;
            max1 = cur;
            i2 = i1;
            i1 = i;
        }
        else if (cur > max2) {
            max2 = cur;
            i2 = i;
        }
    }
    cout << i1 + 1 << ' ' << i2 + 1 << '\n';

    return 0;
}

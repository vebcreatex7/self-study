#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int main() {
    fast;
    ll n, x, y;
    cin >> n >> x >> y;

    ll t = min(x, y);
    n -= 1;
    ll l = 0, r = max(x, y) * n;

    while (l + 1 < r) {
        ll mid = (r + l) / 2;
        if (mid / x + mid / y < n)
            l = mid;
        else r = mid;
    }

    cout << t + r << '\n';




    return 0;
}

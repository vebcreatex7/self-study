#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;


ll nmax(ll l, vector<ll> const &  v) {
    ll n = 0;
    for (auto a : v)
        n += a / l;

    return n;
}


int main() {
    fast;
    int n, k;
    cin >> n >> k;
    ll max = 0;
    ull sum = 0;
    vector<ll> lengths(n);

    for (auto& a : lengths) {
        cin >> a;
        sum += a;
        max = a > max ? a : max;
    }

    if (sum < k) {
        cout << "0\n";
        return 0;
    }



    ll l = 0, r = max + 1;

    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (nmax(mid, lengths) >= k)
            l = mid;
        else r = mid;
    }
    cout << l << endl;
    return 0;
}

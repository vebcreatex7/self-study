#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

bool destinatation(ll x, vector<ll> const& v, ll k) {
    int n = v.size();
    int cow = 1;
    int last_cow = v[0];
    for (auto a : v) {
        if (a - last_cow >= x) {
            cow++;
            last_cow = a;
        }
    }
    return cow >= k;


    return true;
}


int main() {
    fast;
    
    ll n, k;
    cin >> n >> k;
    
    vector<ll> v(n);
    for (auto& a : v)
        cin >> a;
    
    int l = 0, r = v[n - 1] - v[0] + 1;

    while (l + 1 < r) {
        ll mid = (l + r) / 2;
        if (destinatation(mid, v, k))
            l = mid;
        else r = mid;
    }
    cout << l << endl;

    return 0;
}

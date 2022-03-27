#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long

ld const EPS = 1e-12;

using namespace std;

ld f(vector<int> const & v, ld x) {
    int n = v.size();
    ld f = .0;
    for(size_t i = 0; i != n; i++)
        f += (ld) v[i] * pow(x, n - i - 1);
    
    return f;
}





void solve() {
    int x1, y1, rad;
    cin >> x1 >> y1 >> rad;
    int n;
    cin >> n;
    vector<int> poli(n + 1);
    for (auto & a : poli)
        cin >> a;
    ld x;
    cin >> x;
    ld l = -200., r = x;
    cout.precision(16);
    while (r - l > EPS) {
        x = (l + r) / 2.;
        ld f_x = f(poli, x);
        if ((ld)pow(x - x1, 2) + (ld)pow(f_x - y1, 2) < (ld)pow(rad, 2))
            r = x;
        else 
            l = x;
    }
    cout.precision(16);
    cout << (l + r) / 2. << '\n';
}

int main() {
    fast;
    solve();
    
    return 0;
}

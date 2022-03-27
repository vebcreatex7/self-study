#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int gcd(int a, int b) {
    return b == 0 ?  a :  gcd(b, a % b);
}

int main() {
    fast;
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto & a : v)
        cin >> a;

    int g = gcd(v[0], v[1]);
    for (size_t i = 2; i != n; i++) {
        int t = gcd(g, v[i]);
        if (t == 1) {
            g = 1;
            break;
        } else if (t < g)
            g = t;
    }

    cout << g << endl;
    return 0;
}

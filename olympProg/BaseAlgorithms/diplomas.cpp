#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

ull maxn(ull w, ull h, ull mid) {
    return (mid / w) * (mid / h);
}

int main() {
    fast;
    ull w, h, n;
    cin >> w >> h >> n;

    ull l = 0, r = max(w, h) * n;
    while(l + 1 < r) {
        ull mid = (l + r) / 2;
        if (maxn(w, h, mid) < n)
            l = mid;
        else r = mid;
    }
    cout << r << endl;
    return 0;
}

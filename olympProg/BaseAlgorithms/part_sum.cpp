#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int main() {
    fast;
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& c : a)
        cin >> c;
    vector<ll> part_sum(n + 1);
    part_sum[0] = 0;
    for (size_t i = 1; i != n + 1; i++)
        part_sum[i] = part_sum[i - 1] + a[i - 1];

    while (q--) {
        int l, r;
        cin >> l >> r;
        cout << part_sum[r] - part_sum[l - 1] << '\n';
    }
    return 0;
}

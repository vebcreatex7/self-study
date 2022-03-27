#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int main() {
    fast;
    ull n;
    cin >> n;
    ull max = UINT64_MAX;
    ull x = 0;
    if (n % 3 == 0) 
        x = n / 3;
    else if (n % 3 == 1)
        x = n / 3 + 2 * (max / 3) + 1;
    else 
        x = n / 3 + max / 3 + 1;

    cout << x << endl;
    return 0;
}

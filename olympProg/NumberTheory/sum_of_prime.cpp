#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int main() {
    fast;
    
    int n;
    cin >> n;

    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    ll sum = 0;
    for (int i = 2; i  * i <= n; i++) {
        if (primes[i]) {
            for (int j = i * i; j <= n; j += i) {
                if (primes[j])
                    sum += i;
                primes[j] = false;
            }
        }
    }
    cout << sum << endl;


    return 0;
}

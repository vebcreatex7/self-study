#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int main() {
    fast;
    ll n;
    cin >> n;

    if (n == 0 or n == 1) {
        cout << "0\n";
        return 0;
    }

    bool prime = true;
    ll i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            prime = false;
            break;
        }
        i++;
    }

    prime ? cout << "1\n" : cout << "0\n";
        
    
    return 0;
}

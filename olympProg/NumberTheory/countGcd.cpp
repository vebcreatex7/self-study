#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int gcd(int a, int b) {
    static int count = 0;
    if (a < b)
        return gcd(b, a);
    if (b == 0) {
        cout << count;
        return a;
    } else {
        count++;
        return gcd(b, a % b);
    }
    
}

int main() {
    fast;
    int a, b;
    cin >>a >> b;
    gcd (a, b);
    return 0;
}

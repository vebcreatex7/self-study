#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;


int lower_bound(int x, vector<int> const& a) {
    int n = a.size();
    int l = -1, r = n;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] < x)
            l = mid;
        else
            r = mid;
    }
    return r;
}

int upper_bound(int x, vector<int> const& a) {
    int n = a.size();
    int l = -1, r = n;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid;
    }
    return r;
}


bool isNumberIn(int number, vector<int> const& a) {
    int n = a.size();
    int l = -1, r = n;
    while(l + 1 < r) {
        int mid = (l + r) / 2;
        if (a[mid] < number)
            l = mid;
        else 
            r = mid;
    }
    return (r < n && a[r] == number);
}

int main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto& c : a)
        cin >> c;
    
    while(m--) {
        int number;
        cin >> number;
        int pos = upper_bound(number, a);
        pos > 0 ? cout << pos << endl : cout << "NO SOLUTION\n";
    }
    
    return 0;
}

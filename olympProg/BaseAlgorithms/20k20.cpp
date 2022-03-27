#include <bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define ld long double
#define ll long long
#define ull unsigned long long


using namespace std;

int main() {
    fast;
    int MAX_YEAR = int(1e8);
    int year;
    cin >> year;
    bool correct = false;
    while (year < MAX_YEAR) {
        correct = true;
        year++;
        int tmp = year;
        unordered_map<int, int> count;
        while (tmp > 0) {
            int digit = tmp % 10;
            tmp /= 10;
            
            if (digit == 0 or digit == 2) {
                correct = false;
                break;
            }
            else {
                count[digit]++;
                if (count[digit] > 1) {
                    correct = false;
                    break;
                }
            }
        }

        if (correct)
            break;
    
    }
    
    correct ? cout << year << '\n' : cout << "-1\n";


    return 0;
}

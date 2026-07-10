#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
 
        if (n == 0) {
            cout << 10 << '\n';
            continue;
        }
 
        if (n == 1) {
            cout << 1 << '\n';
            continue;
        }
 
        vector<int> digits;
        for (int d = 9; d >= 2; --d) {
            while (n % d == 0) {
                digits.push_back(d);
                n /= d;
            }
        }
 
        if (n > 1) {
            cout << -1 << '\n';
        } else {
            sort(digits.begin(), digits.end());
            for (int d : digits) cout << d;
            cout << '\n';
        }
    }
 
    return 0;
}

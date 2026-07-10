#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;
 
    int l, r;
    while (cin >> l >> r && (l != 0 || r != 0)) {
        --l; --r;
        reverse(a.begin() + l, a.begin() + r + 1);
    }
 
    for (int i = 0; i < n; ++i) {
        if (i) cout << ' ';
        cout << a[i];
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n, q;
    cin >> n >> q;
 
    vector<long long> diff(n + 2, 0);
 
    for (int i = 0; i < q; ++i) {
        int l, r;
        long long v;
        cin >> l >> r >> v;
        diff[l] += v;
        diff[r + 1] -= v;
    }
 
    vector<long long> a(n + 1);
    long long cur = 0;
    for (int i = 1; i <= n; ++i) {
        cur += diff[i];
        a[i] = cur;
    }
 
    for (int i = 1; i <= n; ++i) {
        if (i > 1) cout << ' ';
        cout << a[i];
    }
    cout << '\n';
 
    return 0;
}

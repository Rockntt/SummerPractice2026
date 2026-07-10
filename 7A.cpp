#include <bits/stdc++.h>
using namespace std;

#define all(x) x.begin(), x.end()
using ll = long long;
using pll = array<ll, 2>;

const ll INF = LLONG_MAX;

struct Edge {
    ll u, v, w;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, m, s;
    cin >> n >> m >> s;
    --s;

    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
        --edges[i].u;
        --edges[i].v;
    }

    vector<ll> dp(n, INF);
    dp[s] = 0;

    for (int i = 0; i < n - 1; i++) {
        bool updated = false;
        for (const auto& e : edges) {
            if (dp[e.u] != INF && dp[e.v] > dp[e.u] + e.w) {
                dp[e.v] = dp[e.u] + e.w;
                updated = true;
            }
        }
        if (!updated) break;
    }

    for (const auto& e : edges) {
        if (dp[e.u] != INF && dp[e.v] > dp[e.u] + e.w) {
            cout << "Negative cycle\n";
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (dp[i] == INF) {
            cout << "inf" << ' ';
        }
        else {
            cout << dp[i] << ' ';
        }
    }

    return 0;
}

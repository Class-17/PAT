#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

constexpr int inf = 0x3f3f3f3f;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    int q; cin >> q;
    for (int i = 0; i < q; ++i) {
        vector<int> seq(n);
        for (auto &x : seq) cin >> x;
            auto dijkstra = [&](int s) {
                vector<int> dist(n + 1, inf);
                dist[s] = 0;
                priority_queue<pii, vector<pii>, greater<pii>> pq;
                pq.emplace(0, s);
                while (!pq.empty()) {
                    auto [d, u] = pq.top(); pq.pop();
                    if (dist[u] < d) continue;
                    for (auto &[v, w] : g[u]) {
                        if (dist[v] <= d + w) continue;
                        dist[v] = d + w;
                        pq.emplace(d + w, v);
                    }
                }
                for (int i = 0; i < n; ++i)
                    seq[i] = dist[seq[i]];
                return is_sorted(begin(seq), end(seq));
            };
        cout << (dijkstra(seq[0]) ? "Yes" : "No") << '\n';
    }
    return 0;
}
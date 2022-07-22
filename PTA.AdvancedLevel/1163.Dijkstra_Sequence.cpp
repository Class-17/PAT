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
                reverse(begin(seq), end(seq));
                vector<int> dist(n + 1, inf);
                dist[s] = 0;
                priority_queue<pii, vector<pii>, greater<pii>> pq;
                pq.emplace(0, s);
                vector<int> curr;
                int pred = -1;
                while (!pq.empty()) {
                    auto [d, u] = pq.top(); pq.pop();
                    if (dist[u] < d) continue;
                    if (d != pred) {
                        vector<int> temp;
                        while (size(temp) < size(curr)) {
                            temp.push_back(seq.back());
                            seq.pop_back();
                        }
                        sort(begin(curr), end(curr));
                        sort(begin(temp), end(temp));
                        if (curr != temp) return false;
                        curr.clear();
                        pred = d;
                    }
                    curr.push_back(u);
                    for (auto &[v, w] : g[u]) {
                        if (dist[v] <= d + w) continue;
                        dist[v] = d + w;
                        pq.emplace(d + w, v);
                    }
                }
                return true;
            };
        cout << (dijkstra(seq[0]) ? "Yes" : "No") << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, ds;
    cin >> n >> m >> k >> ds;
    vector<vector<pii>> g(n + m);
    for (int i = 0; i < k; ++i) {
        string a, b;
        int d;
        cin >> a >> b >> d;
        int u = (a[0] == 'G' ? stoi(a.substr(1)) + n: stoi(a));
        int v = (b[0] == 'G' ? stoi(b.substr(1)) + n: stoi(b));
        g[u - 1].emplace_back(v - 1, d);
        g[v - 1].emplace_back(u - 1, d);
    }
    auto dijkstra = [&](int s)->pair<int, double> {
        vector<int> dist(n + m, ds + 1);
        dist[s] = 0;
        priority_queue<pii, vector<pii>, greater<>> pq;
        pq.emplace(0, s);
        while (!pq.empty()) {
            const auto [d, u] = pq.top(); pq.pop();
            if (dist[u] < d) continue;
            for (auto &[v, w] : g[u]) {
                if (dist[v] <= d + w) continue;
                dist[v] = d + w;
                pq.emplace(dist[v], v);
            }
        }
        for (int i = 0; i < n; ++i)
            if (dist[i] > ds) return {-1, -1};
        int min_dist = *min_element(begin(dist), begin(dist) + n);
        double sum = accumulate(begin(dist), begin(dist) + n, 0);
        return {min_dist, sum / n};
    };
    vector<tuple<double, double, int>> res;
    for (int i = 0; i < m; ++i) {
        auto [min_dist, avg] = dijkstra(i + n);
        if (min_dist == -1) continue;
        res.emplace_back(-min_dist, avg, i);
    }
    sort(begin(res), end(res));
    if (res.empty())
        cout << "No Solution" << '\n';
    else {
        auto &[min_dist, avg, idx] = res[0];
        cout << "G" << idx + 1 << '\n';
        cout << setprecision(1) << fixed << round(-min_dist * 10) / 10 << ' ';
        cout << setprecision(1) << fixed << round(avg * 10) / 10 << '\n';
    }
    return 0;
}
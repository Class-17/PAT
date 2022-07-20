#include <bits/stdc++.h>
using namespace std;

constexpr double r = 0.2;

constexpr int lim = 5;

constexpr int maxn = 1e3 + 1;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int k, n, m;
    cin >> k >> n >> m;
    vector<map<int, int>> g(n + 1);
    vector<tuple<int, int, int>> input(m);
    for (auto &[a, b, w] : input) {
        cin >> a >> b >> w;
        g[a][b] += w;
    }
    bitset<maxn> st;
    for (int i = 1; i <= n; ++i) {
        int outD = 0, backD = 0;
        for (auto &[j, w] : g[i]) {
            if (w > lim) continue;
            ++outD;
            if (g[j].find(i) != g[j].end()) ++backD;
        }
        if (outD > k and backD <= outD * r) st[i] = 1;
    }
    vector<vector<int>> gg(n + 1);
    for (auto &[a, b, w] : input)
        if (st[a] and st[b] and g[b].find(a) != g[b].end())
            gg[a].push_back(b);
    vector<vector<int>> gangs;
    auto dfs = [&](auto &dfs, int u) {
        if (!st[u]) return;
        st[u] = 0;
        gangs.back().push_back(u);
        for (auto &v : gg[u])
            dfs(dfs, v);
    };
    for (int i = 1; i <= n; ++i) {
        if (!st[i]) continue;
        gangs.push_back({});
        dfs(dfs, i);
    }
    for (auto &gang : gangs)
        sort(begin(gang), end(gang));
    sort(begin(gangs), end(gangs));
    if (gangs.empty()) cout << "None" << '\n';
    else {
        for (auto &gang : gangs)
            for (int i = 0; i < size(gang); ++i)
                cout << gang[i] << (i + 1 < size(gang) ? ' ' : '\n');
    }
    return 0;
}
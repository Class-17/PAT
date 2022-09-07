#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, t;
    cin >> n >> t;
    vector<int> in(n), out(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        for (int j = 0; j < m; ++j) {
            int u; cin >> u;
            g[i].push_back(u - 1);
            ++in[u - 1];
        }
        out[i] += m;
    }
    vector<int> seq;
    for (int i = 0; i < n; ++i)
        if (in[i] >= out[i] * t)
            seq.push_back(i);
    vector<int> cnt(n);
    for (auto &u : seq)
        for (auto &v : g[u])
            ++cnt[v];
    int max_num = 0;
    for (auto &u : seq)
        max_num = max(max_num, cnt[u]);
    vector<int> res;
    for (auto &u : seq)
        if (cnt[u] == max_num) res.push_back(u);
    int len = size(res);
    for (int i = 0; i < len; ++i)
        cout << res[i] + 1 << (i + 1 < len ? ' ' : '\n');
    return 0;
}
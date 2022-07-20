#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, k; cin >> x >> k;
        g[x].resize(k);
        for (auto &y : g[x]) 
            cin >> y;
    }
    vector<int> depth(n + 1);
    auto dfs = [&](auto &dfs, int x, int d)->void {
        depth[d]++;
        for (auto &y : g[x]) 
            dfs(dfs, y, d + 1);
    };
    dfs(dfs, 1, 1);
    auto p = max_element(begin(depth), end(depth));
    cout << *p << ' ' << p - begin(depth) << endl;
    return 0;
}
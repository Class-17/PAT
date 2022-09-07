#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 2; i <= n; ++i) {
        int x; cin >> x;
        g[x].push_back(i);
    }
    int m; cin >> m;
    vector<int> cnt(n + 1);
    auto dfs = [&](auto &dfs, int idx)->int {
        int res = 1;
        for (auto &v : g[idx])
            res += dfs(dfs, v);
        return cnt[idx] = res;
    };
    cnt[1] = dfs(dfs, 1);
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        cout << cnt[x] << '\n';
    }
    return 0;
}
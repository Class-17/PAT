#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e3 + 1;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    bitset<maxn> g[maxn];
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u][v] = 1;
    }
    for (int i = 0; i < k; ++i) {
        vector<int> seq(n);
        for (auto &x : seq) cin >> x;
        auto check = [&]() {
            bitset<maxn> curr;
            auto dfs = [&](auto &dfs, int &idx)->bool {
                auto x = seq[idx];
                if (curr[x]) return false;
                curr[x] = 1;
                while (idx + 1 < n and g[x][seq[idx + 1]]) {
                    ++idx;
                    if (!dfs(dfs, idx)) return false;
                }
                for (int i = 1; i <= n; ++i)
                    if (g[x][i] and !curr[i]) return false;
                return true;  
            }; 
            int i = 0;
            while (i < n) {
                if (!dfs(dfs, i)) return false;
                ++i;
            }
            return true;
        };
        cout << (check() ? "yes" : "no") << '\n';
    }
    return 0;
}
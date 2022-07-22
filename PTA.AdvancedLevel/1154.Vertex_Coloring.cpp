#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int k; cin >> k;
    for (int i = 0; i < k; ++i) {
        vector<int> seq(n);
        for (auto &x : seq) cin >> x;
        auto check = [&]() {
            for (int u = 0; u < n; ++u)
                for (auto &v : g[u])
                    if (seq[u] == seq[v]) return false;
            return true;
        };
        if (check())
            cout << set<int>(begin(seq), end(seq)).size() << "-coloring" << '\n';
        else
            cout << "No" << '\n';
    }
    return 0;
}
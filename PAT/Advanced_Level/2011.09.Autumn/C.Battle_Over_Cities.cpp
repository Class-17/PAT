#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1000;

bitset<maxn> st;

vector<vector<int>> g;

void dfs(int u) {
    if (st[u]) return;
    st[u] = 1;
    for (auto &v : g[u])
        if (!st[v]) dfs(v);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k;
    cin >> n >> m >> k;
    g = vector<vector<int>>(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for (int i = 0; i < k; ++i) {
        int v; cin >> v;
        st.reset();
        st[v - 1] = 1;
        int cnt = 0;
        for (int j = 0; j < n; ++j) {
            if (st[j]) continue;
            dfs(j);
            ++cnt;
        }
        cout << cnt - 1 << '\n';
    }
    return 0;
}
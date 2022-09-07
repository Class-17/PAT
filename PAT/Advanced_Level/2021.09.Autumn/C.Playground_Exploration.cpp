#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    for (auto &seq : g)
        sort(begin(seq), end(seq));
    int res = 1, len = 1;
    for (int i = 1; i <= n; ++i) {
        set<int> st;
        int idx = i, curr = 0;
        while (true) {
            st.insert(idx);
            int pre = idx;
            ++curr;
            for (auto &v : g[idx]) {
                if (st.find(v) != st.end()) continue;
                idx = v;
                break;
            }
            if (idx == pre) break;
        }
        if (curr > len)
            tie(res, len) = pair{i, curr};
    }
    cout << res << ' ' << len << '\n';
    return 0;
}
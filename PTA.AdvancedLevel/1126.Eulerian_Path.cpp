#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> de(n);
    vector<vector<int>> g(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a - 1].push_back(b - 1);
        g[b - 1].push_back(a - 1);
        ++de[a - 1];
        ++de[b - 1];
    }
    int odd = 0, even = 0;
    for (auto &x : de)
        if (x & 1) ++odd;
        else       ++even;
    for (int i = 0; i < n; ++i)
        cout << de[i] << (i + 1 < n ? ' ' : '\n');
    auto isConnected = [&]() {
        set<int> st;
        auto dfs = [&](auto &dfs, int idx) {
            if (st.find(idx) != st.end()) return;
            st.insert(idx);
            for (auto &u : g[idx])
                dfs(dfs, u);
            return;
        };
        dfs(dfs, 0);
        return size(st) == n;
    };
    if (even == n and isConnected())
        cout << "Eulerian" << '\n';
    else if (odd == 2)
        cout << "Semi-Eulerian" << '\n';
    else
        cout << "Non-Eulerian" << '\n';
    return 0;
}
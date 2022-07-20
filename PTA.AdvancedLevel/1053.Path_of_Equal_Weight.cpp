#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    vector<pair<int, vector<int>>> tree(n);
    for (auto &[x, _] : tree) cin >> x;
    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;
        tree[id].second.resize(k);
        for (auto &x : tree[id].second) cin >> x;
    }
    vector<vector<int>> res; 
    vector<int> seq;
    int sum = 0;
    auto dfs = [&](auto &dfs, int t, vector<int>& seq) {
        if (sum > s) return;
        seq.push_back(tree[t].first);
        sum += tree[t].first;
        if (tree[t].second.empty() && sum == s)
            res.push_back(seq);
        for (auto &x : tree[t].second)
            dfs(dfs, x, seq);
        sum -= tree[t].first;
        seq.pop_back();
    };
    dfs(dfs, 0, seq);
    sort(rbegin(res), rend(res));
    for (auto &x : res)
        for (int i = 0; i < size(x); ++i)
            cout << x[i] << (i + 1 < size(x) ? ' ' : '\n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> tree(n);
    for (int i = 0; i < n; ++i)
        cin >> tree[i].first >> tree[i].second;
    vector<int> seq(n), val(n), res;
    for (auto &x : seq) cin >> x;
    sort(rbegin(seq), rend(seq));
    auto dfs = [&](auto &dfs, int x) {
        if (x == -1) return;
        dfs(dfs, tree[x].first);
        val[x] = seq.back();
        seq.pop_back();
        dfs(dfs, tree[x].second);
    };
    dfs(dfs, 0);
    queue<int> q;
    q.push(0);
    while (!q.empty()) {
        int len = size(q);
        while (len--) {
            auto x = q.front();
            q.pop();
            res.push_back(val[x]);
            if (tree[x].first != -1)
                q.push(tree[x].first);
            if (tree[x].second != -1)
                q.push(tree[x].second);
        }
    }
    for (int i = 0; i < n; ++i)
        cout << res[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
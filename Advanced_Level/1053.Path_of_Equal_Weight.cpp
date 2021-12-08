#include <bits/stdc++.h>
using namespace std;

struct node {
    int val; 
    vector<int> seq;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    vector<node> tree(n);
    for (auto &[x, _] : tree) cin >> x;
    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;
        tree[id].seq.resize(k);
        for (int j = 0; j < k; ++j)
            cin >> tree[id].seq[j];
    }
    vector<vector<int>> res; 
    vector<int> seq;
    int sum = 0;
    auto dfs = [&](auto &dfs, int t, vector<int>& seq) {
        if (sum > s) return;
        seq.push_back(tree[t].val);
        sum += tree[t].val;
        if (tree[t].seq.empty()) {
            if (sum == s) res.push_back(seq);
        }
        for (auto &x : tree[t].seq)
            dfs(dfs, x, seq);
        sum -= tree[t].val;
        seq.pop_back();
    };
    dfs(dfs, 0, seq);
    sort(rbegin(res), rend(res));
    for (auto &x : res)
        for (int i = 0; i < size(x); ++i)
            cout << x[i] << (i + 1 < size(x) ? ' ' : '\n');
    return 0;
}
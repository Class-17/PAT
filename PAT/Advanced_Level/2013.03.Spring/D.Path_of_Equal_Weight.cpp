#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, s;
    cin >> n >> m >> s;
    vector<pair<int, vector<int>>> tree(n);
    for (auto &[val, seq] : tree)
        cin >> val;
    for (int i = 0; i < m; ++i) {
        int id, k;
        cin >> id >> k;
        for (int j = 0; j < k; ++j) {
            int idx; cin >> idx;
            tree[id].second.push_back(idx);
        }
    }
    vector<vector<int>> res;
    vector<int> curr;
    auto dfs = [&](auto &dfs, int idx, int sum) {
        if (sum > s) return;
        if (sum == s and tree[idx].second.empty())
            res.push_back(curr);
        for (auto &son : tree[idx].second) {
            curr.push_back(tree[son].first);
            dfs(dfs, son, sum + tree[son].first);
            curr.pop_back();
        }   
    };
    curr.push_back(tree[0].first);
    dfs(dfs, 0, tree[0].first);
    sort(rbegin(res), rend(res));
    for (auto &seq : res)
        for (int i = 0; i < size(seq); ++i)
            cout << seq[i] << (i + 1 < size(seq) ? ' ' : '\n');
    return 0;
}
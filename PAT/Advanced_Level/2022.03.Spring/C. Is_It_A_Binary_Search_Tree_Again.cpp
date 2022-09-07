#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> ord(n);
    for (auto &x : ord) cin >> x;
    vector<int> seq;
    auto dfs = [&](auto &dfs, int idx) {
        if (idx >= n or ord[idx] == -1) return;
        dfs(dfs, idx * 2 + 1);
        seq.push_back(ord[idx]);
        dfs(dfs, idx * 2 + 2);
    };
    dfs(dfs, 0);
    int len = size(seq);
    cout << (is_sorted(begin(seq), end(seq)) ? "YES" : "NO") << '\n';
    for (int i = 0; i < len; ++i)
        cout << seq[i] << (i + 1 < len ? ' ' : '\n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> seq(n);
    for (auto &x : seq) cin >> x;
    sort(rbegin(seq), rend(seq));
    vector<int> res(n);
    auto dfs = [&](auto &dfs, int x) {
        if (x >= n) return;
        dfs(dfs, x * 2 + 1);
        res[x] = seq.back();
        seq.pop_back();
        dfs(dfs, x * 2 + 2);
    };
    dfs(dfs, 0);
    for (int i = 0; i < n; ++i)
        cout << res[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
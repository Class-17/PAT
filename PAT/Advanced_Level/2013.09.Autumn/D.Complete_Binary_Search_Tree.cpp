#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> seq(n);
    for (auto &x : seq) cin >> x;
    sort(rbegin(seq), rend(seq));
    vector<int> arr(n);
    auto dfs = [&](auto &dfs, int idx) {
        if (idx >= n) return;
        dfs(dfs, idx * 2 + 1);
        arr[idx] = seq.back();
        seq.pop_back();
        dfs(dfs, idx * 2 + 2);
    };
    dfs(dfs, 0);
    for (int i = 0; i < n; ++i)
        cout << arr[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
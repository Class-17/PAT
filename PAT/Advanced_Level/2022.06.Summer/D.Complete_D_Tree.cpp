#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, d;
    cin >> n >> d;
    vector<int> preO(n);
    for (auto &x : preO) cin >> x;
    vector<int> seq(n);
    auto dfs = [&](auto &dfs, int &idx, int p) {
        if (p >= n or idx >= n) return;
        seq[p] = preO[idx++];
        for (int i = 1; i <= d; ++i)
            dfs(dfs, idx, p * d + i);
    };
    int idx = 0;
    dfs(dfs, idx, 0);
    for (int i = 0; i < n; ++i)
        cout << seq[i] << (i + 1 < n ? ' ' : '\n');
    int k; cin >> k;
    for (int i = 0; i < k; ++i) {
        int p; cin >> p;
        while (p > 0) {
            cout << seq[p] << ' ';
            p = (p - 1) / d;
        }
        cout << seq[0] << '\n';
    }
    return 0;
}
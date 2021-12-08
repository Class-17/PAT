#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double p, r;
    cin >> n >> p >> r;
    vector<vector<int>> g(n);
    vector<int> cnt(n);
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        if (k > 0) {
            g[i].resize(k);
            for (int j = 0; j < k; ++j)
                cin >> g[i][j];
        }
        else
            cin >> cnt[i];
    }
    auto dfs = [&](auto &dfs, int x, double price) {
        if (g[x].empty()) return price * cnt[x];
        double sum = 0.0;
        for (auto &y : g[x])
            sum += dfs(dfs, y, price * (1.0 + r * 0.01));
        return sum;
    };
    cout << fixed << setprecision(1) << dfs(dfs, 0, p) << endl;
    return 0;
}
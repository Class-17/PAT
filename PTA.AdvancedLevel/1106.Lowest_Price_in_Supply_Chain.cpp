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
        g[i].resize(k);
        for (int j = 0; j < k; ++j)
            cin >> g[i][j];
    }
    vector<double> price(n, 1e10 + 1);
    auto dfs = [&](auto &dfs, int x, double val)->void {
        if (g[x].empty()) 
            price[x] = val;
        double sum = 0.0;
        for (auto &y : g[x])
            dfs(dfs, y, val * (1.0 + r * 0.01));
    };
    dfs(dfs, 0, p);
    double min_price = *min_element(begin(price), end(price));
    cout << fixed << setprecision(4) << min_price << ' ';
    cout << count(begin(price), end(price), min_price) << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    double p, r;
    cin >> n >> p >> r;
    vector<vector<int>> g(n);
    int root;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        if (x != -1) g[x].push_back(i);
        else         root = i;
    }
    vector<double> price(n);
    auto dfs = [&](auto &dfs, int x, double val)->void {
        if (g[x].empty())
            price[x] = val;
        for (auto &y : g[x])
            dfs(dfs, y, val * (1.0 + r * 0.01));
    };
    dfs(dfs, root, p);
    double max_price = *max_element(begin(price), end(price));
    cout << fixed << setprecision(2) << max_price << ' ';
    cout << count(begin(price), end(price), max_price) << endl;
    return 0;
}
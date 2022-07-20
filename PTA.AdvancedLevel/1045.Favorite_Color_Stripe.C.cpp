#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l;
    cin >> n >> m;
    vector<int> a(m, -1);
    for (auto &x : a) cin >> x;
    vector<int> f(n + 1, -1);
    for (int i = 0; i < m; ++i)
        f[a[i]] = i;
    cin >> l;
    vector<int> seq(l);
    for (auto &x : seq) cin >> x;
    vector<int> dp;
    for (auto &x : seq) {
        if (f[x] == -1) continue;
        auto pos = upper_bound(begin(dp), end(dp), x, [&](const auto &a, const auto &b) {
            return f[a] < f[b];});
        if (pos != end(dp)) *pos = min(x, *pos);
        else                dp.push_back(x);
    }
    cout << size(dp) << '\n';
    return 0;
}
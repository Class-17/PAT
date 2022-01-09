#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<pair<double, double>> cakes(n);
    for (auto &[_, w] : cakes) cin >> w;
    for (auto &[p, w] : cakes) {
        cin >> p;
        p /= w;
    }
    sort(rbegin(cakes), rend(cakes));
    double profit = 0.0;
    for (int i = 0; i < n && m > 0; ++i) {
        int w = min(cakes[i].second, double(m));
        profit += w * cakes[i].first;
        m -= w;
    }
    cout << setprecision(2) << fixed << profit << '\n';
    return 0;
}
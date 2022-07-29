#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    double m;
    cin >> n >> m;
    vector<pair<double, double>> arr(n);
    for (auto &[w, p] : arr) cin >> w;
    for (auto &[w, p] : arr) cin >> p;
    sort(begin(arr), end(arr), [](const auto &a, const auto &b) {
        return a.second / a.first > b.second / b.first;
    });
    double cost = 0.0;
    for (auto &[w, p] : arr) {
        if (!m) break;
        double curr = min(m, w);
        cost += p / w * curr;
        m -= curr;
    }
    cout << setprecision(2) << fixed << cost << '\n';
    return 0;
}
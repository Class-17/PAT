#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    double cap, d, s, n;
    cin >> cap >> d >> s >> n;
    vector<pair<double, double>> seq(n);
    for (auto &[dist, p] : seq) cin >> p >> dist;
    sort(begin(seq), end(seq));
    seq.emplace_back(d, DBL_MAX);
    double fee = 0.0, tank = 0.0, p = 0.0;
    auto get_gas = [&](int pos) {
        double able_p = seq[pos].first + cap * s;
        int np = n;
        for (int i = pos + 1; i <= n && seq[i].first <= able_p; ++i)
            if (seq[i].second < seq[pos].second) {
                np = i; break;
            }
        double gas = (seq[np].first - seq[pos].first) / s;
        return gas > cap ? cap - tank : max(gas - tank, 0.0);
    };
    for (int i = 0; i <= n; ++i) {
        tank -= (seq[i].first - p) / s;
        if (tank < 0) {
            p = seq[i].first + tank * s;
            break;
        }
        double gas = get_gas(i);
        fee += gas * seq[i].second;
        tank += gas;
        p = seq[i].first;
    }
    if(p < d) cout << "The maximum travel distance = " 
                   << setprecision(2) << fixed << p << '\n';
    else      cout << setprecision(2) << fixed << fee << '\n';
    return 0;
}
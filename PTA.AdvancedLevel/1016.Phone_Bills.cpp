#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> w(24);
    for (auto &x : w) cin >> x;
    int sum = accumulate(begin(w), end(w), 0);
    int n; cin >> n;
    vector<vector<string>> calls(n, vector<string>(3));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cin >> calls[i][j];
    auto convert = [](const string &s) {
        int res = 0, cast[] = {0, 31, 24, 60};
        for (int i = 0; i < size(s); i += 3)
            res = res * cast[i / 3] + stoi(s.substr(i, 2));
        return res;
    };
    sort(begin(calls), end(calls), [&](const auto &a, const auto &b) {
        if (a[0] == b[0]) return convert(a[1]) < convert(b[1]);
        return a[0] < b[0];});
    int p = 0;
    while (p < n) {
        int np = p + 1;
        while (np < n && calls[np][0] == calls[p][0]) np++;
        vector<pair<string, string>> user;
        for (int i = p + 1; i < np; ++i)
            if (calls[i - 1][2][1] == 'n' && calls[i][2][1] == 'f' && calls[i - 1][0] == calls[i][0])
                user.emplace_back(calls[i -  1][1], calls[i][1]);
        p = np;
        if (user.empty()) continue;
        cout << calls[p - 1][0] << ' ' << calls[p - 1][1].substr(0, 2) << '\n';
        double cost = 0.0;
        auto count = [&](string &s) {
            int d = stoi(s.substr(3, 2));
            int h = stoi(s.substr(6, 2));
            int m = stoi(s.substr(9, 2));
            int fee = w[h] * m + sum * 60 * d;
            for (int i = 0; i < h; ++i)
                fee += w[i] * 60;
            return fee / 100.0;
        };
        for (auto &[a, b] : user) {
            double curr = count(b) - count(a);
            cout << a.substr(3) << ' ' << b.substr(3) << ' ' << convert(b) - convert(a) << " $"
                 << setprecision(2) << fixed << curr << '\n';
            cost += curr;
        }
        cout << "Total amount: $" << setprecision(2) << fixed << cost << '\n';
    }
    return 0;
}
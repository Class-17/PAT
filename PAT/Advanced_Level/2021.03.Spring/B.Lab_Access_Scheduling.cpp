#include <bits/stdc++.h>
using namespace std;

int convert(const string &s) {
    int hh = stoi(s.substr(0, 2));
    int mm = stoi(s.substr(3, 2));
    int ss = stoi(s.substr(6, 2));
    return hh * 3600 + mm * 60 + ss;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int ,int>> arr(n);
    for (auto &[a, b] : arr) {
        string aa, bb;
        cin >> aa >> bb;
        a = convert(aa);
        b = convert(bb);
    }
    sort(begin(arr), end(arr), [](const auto &a, const auto &b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second < b.second;
    });
    int res = 0, lim = 0;
    for (auto &[lo, hi] : arr) {
        if (lo < lim) continue;
        lim = hi;
        ++res;
    }
    cout << res << '\n';
    return 0;
}
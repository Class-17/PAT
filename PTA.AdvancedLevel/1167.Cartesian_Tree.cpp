#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> seq(n);
    for (auto &x : seq) cin >> x;
    queue<pair<int, int>> q;
    q.emplace(0, n);
    vector<int> res;
    while (!q.empty()) {
        int len = size(seq);
        while (len--) {
            auto [lo, hi] = q.front(); q.pop();
            int p = min_element(begin(seq) + lo, begin(seq) + hi) - begin(seq);
            res.push_back(seq[p]);
            if (p > lo) q.emplace(lo, p);
            if (p + 1 < hi) q.emplace(p + 1, hi);
        }
    }
    for (int i = 0; i < n; ++i)
        cout << res[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
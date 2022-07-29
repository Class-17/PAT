#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &seq, int m) {
    int n = size(seq);
    set<int> lo, hi(begin(seq), end(seq));
    for (int i = 0; i < n; ++i) {
        if (seq[i] - i > m) return false;
        if (i > 0 and i + 1 < n) {
            auto left = rbegin(lo);
            auto right = hi.upper_bound(seq[i]);
            if (right != end(hi) and *left > *right)
                return false;
        }
        lo.insert(seq[i]);
        hi.erase(seq[i]);
    }
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n, k;
    cin >> m >> n >> k;
    for (int i = 0; i < k; ++i) {
        vector<int> seq(n);
        for (auto &x : seq) cin >> x;
        cout << (check(seq, m) ? "YES" : "NO") << '\n';
    }
    return 0;
}
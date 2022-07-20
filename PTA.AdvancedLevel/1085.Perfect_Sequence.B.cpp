#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long n, p;
    cin >> n >> p;
    vector<int> seq(n);
    for (auto& x : seq) cin >> x;
    sort(seq.begin(), seq.end());
    int max_len = 0, lo = 0, hi = 0;
    while (lo < n && hi < n) {
        while (hi < n && seq[hi] <= seq[lo] * p) hi++;
        max_len = max(max_len, hi - lo);
        lo++;
    }
    cout << max_len << '\n';
    return 0;
}
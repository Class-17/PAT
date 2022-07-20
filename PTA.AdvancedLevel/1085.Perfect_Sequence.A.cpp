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
    int max_len = 0;
    for (int i = 0; i < n; ++i) {
        int loc = upper_bound(begin(seq), end(seq), seq[i] * p) - begin(seq);
        max_len = max(loc - i, max_len);
    }
    cout << max_len << '\n';
    return 0;
}
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
    vector<int> dp(l);
    for (int i = 0; i < l; ++i) {
        if (f[seq[i]] >= 0) dp[i] = 1;
        for (int j = 0; j < i; ++j)
            if (f[seq[i]] >= 0 && f[seq[i]] >= f[seq[j]])
                dp[i] = max(dp[j] + 1, dp[i]);
    }
    cout << *max_element(begin(dp), end(dp)) << '\n';
    return 0;
}
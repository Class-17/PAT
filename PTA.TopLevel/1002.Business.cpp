#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<tuple<int, int, int>> arr(n);
    for (auto &[d, l, p] : arr)
        cin >> p >> l >> d;
    sort(begin(arr), end(arr));
    map<int, int, greater<>> dp{{0, 0}};
    int res = 0;
    for (auto &[d, l, p] : arr)
        for (auto &[t, w] : dp) {
            if (t + l > d) continue;
            dp[t + l] = max(dp[t + l], w + p);
            res = max(res, dp[t + l]);
        }
    cout << res << '\n';
    return 0;
}
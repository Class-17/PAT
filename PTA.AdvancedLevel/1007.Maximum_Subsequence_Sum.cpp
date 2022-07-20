#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int k; cin >> k;
    vector<int> seq(k);
    for (auto &x : seq) cin >> x;
    vector<int> curr(2, -1);
    vector dp = {-1, seq.front(), seq.back()};
    for (int i = 0; i < k; i++) {
        if (curr[0] >= 0)
            curr[0] += seq[i];
        else
            curr[0] = curr[1] = seq[i];
        if (curr[0] > dp[0]) 
            tie(dp[0], dp[1], dp[2]) = tuple{curr[0], curr[1], seq[i]};
    }
    if (dp[0] == -1) dp[0] = 0;
    for (int i = 0; i < 3; ++i)
        cout << dp[i] << (i < 2 ? ' ' : '\n');
    return 0;
}
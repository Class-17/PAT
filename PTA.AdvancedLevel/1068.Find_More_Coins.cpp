#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>& coins, int m) {
    vector<vector<int>> dp(m + 1);
    for (auto &coin : coins) {
        for (int i = m - coin; i > 0; --i) {
            if (dp[i].empty()) continue;
            if (dp[i + coin].empty()) {
                dp[i + coin] = dp[i];
                dp[i + coin].push_back(coin);
            }
            else {
                auto curr = dp[i];
                curr.push_back(coin);
                if (curr < dp[i + coin])
                    dp[i + coin] = move(curr);
            }
        }
        if (dp[coin].empty()) 
            dp[coin].push_back(coin);
    }
    return dp[m];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for (auto &x : coins) cin >> x;
    sort(begin(coins), end(coins));
    coins.erase(upper_bound(coins.begin(), coins.end(), m), coins.end());
    auto res = solve(coins, m);
    if (res.empty()) 
        cout << "No Solution" << '\n';
    else
        for (int i = 0;  i < size(res); ++i)
            cout << res[i] << (i + 1 < size(res) ? ' ' : '\n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

string toZJU(vector<int>& coins, int m) {
    vector<pair<int, string>> dp(m + 1);
    for(auto coin : coins) {
        string num = to_string(coin);
        while (num.size() < 3)
            num.insert(num.begin(), '0');
        for(int j = m - coin; j > 0; j--) {
            if(dp[j].first != 0) {
               if(dp[j + coin].first == 0) {
                    dp[j + coin].first = j + coin;
                    dp[j + coin].second = dp[j].second + num;
               }
               else if(dp[j].second + num < dp[j + coin].second)
                    dp[j + coin].second = dp[j].second + num;
            }
        }
        if(dp[coin].first == 0) {
            dp[coin].first = coin;
            dp[coin].second = num;
        }
    }
    if(dp[m].first == 0) return "No Solution";
    return dp[m].second;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> coins(n);
    for(auto& coin : coins) cin >> coin;
    sort(coins.begin(), coins.end());
    coins.erase(upper_bound(coins.begin(), coins.end(), m), coins.end());
    string ans = toZJU(coins, m);
    if(ans[0] == 'N') cout << ans << endl;
    else
        for(int i = 0; i + 2 < ans.size(); i += 3)
            cout << stoi(ans.substr(i, 3)) 
                 << (i + 3 < ans.size() ? ' ' : '\n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    int n = size(s);
    vector<vector<bool>> dp(n, vector<bool>(n));
    int max_len = 1;
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
        if (i + 1 < n && s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            max_len = 2;
        }   
    }
    for (int i = 3; i <= n; ++i)
        for (int j = 0; j + i <= n; ++j)
            if (dp[j + 1][j + i - 2] && s[j] == s[j + i - 1]) {
                dp[j][j + i - 1] = true;
                max_len = i;
            }
    cout << max_len << '\n';
    return 0;
}
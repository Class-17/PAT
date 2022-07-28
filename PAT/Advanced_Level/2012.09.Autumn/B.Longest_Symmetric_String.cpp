#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    getline(cin, s);
    int n = size(s);
    vector<vector<bool>> dp(n, vector<bool>(n));
    int len = 1;
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
        if (i + 1 >= n or s[i] != s[i + 1]) continue;
        dp[i][i + 1] = true;
        len = 2;
    }
    for (int i = 3; i <= n; ++i)
        for (int j = 0; j + i <= n; ++j) {
            if (s[j] != s[j + i - 1]) continue;
            if (!dp[j + 1][j + i - 2]) continue;
            dp[j][j + i - 1] = true;
            len = i;
        }
    cout << len << '\n';
    return 0;
}
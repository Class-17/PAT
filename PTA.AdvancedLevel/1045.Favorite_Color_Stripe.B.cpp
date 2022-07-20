#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l;
    cin >> n >> m;
    vector<int> a(m + 1);
    for (int i = 1; i <= m; ++i)
        cin >> a[i];
    cin >> l;
    vector<int> b(l + 1);
    for (int i = 1; i <= l; ++i)
        cin >> b[i];
    vector<vector<int>> dp(m + 1, vector<int>(l + 1));
    for (int i = 1; i <= m; ++i)
        for (int j = 1; j <= l; ++j)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + (a[i] == b[j]);
    cout << dp[m][l] << '\n';
    return 0;
}
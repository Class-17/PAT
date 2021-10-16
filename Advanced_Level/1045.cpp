#include <bits/stdc++.h>
using namespace std;

int getLCS(vector<int>& colors, vector<int>& favColors) {
    vector<vector<int>> dp(colors.size() + 1,
         vector<int> (favColors.size() + 1, 0));
    for(int i = 1; i < dp.size(); i++)
        for(int j = 1; j < dp[i].size(); j++)
            if(colors[i - 1] == favColors[j - 1])
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + 1;
            else   
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
    return dp[colors.size()][favColors.size()];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, l;
    cin >> n >> m;
    vector<int> favColors(m);
    for(auto& color : favColors) cin >> color;
    cin >> l;
    vector<int> colors(l);
    for(auto& color : colors) cin >> color;
    cout << getLCS(colors, favColors) << endl;
    return 0;
}
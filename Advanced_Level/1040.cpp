#include <bits/stdc++.h>
using namespace std;

int getLSS(string& s) {
    int lss = 1;
    vector<vector<bool>> dp(s.size(), 
        vector<bool> (s.size()));
    for(int i = 0; i < dp.size(); i++) {
        dp[i][i] = true;
        if(i + 1 < dp.size() && s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            lss = 2;
        }
    }
    for(int len = 3; len <= s.size(); len++)
        for(int i = 0; i + len - 1 < dp.size(); i++) {
            int j = i + len - 1;
            if(s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                lss = len;
            }
        }
    return lss;
}

int main()
{
    string s;
    getline(cin, s);
    cout << getLSS(s) << endl;
    return 0;
}
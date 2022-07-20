#include <bits/stdc++.h>
using namespace std;

constexpr int R = 7, C = 5;

constexpr int maxn = 26;

array<string, R> mp[maxn];

bool check(const char &ch) {
    return ch >= 'A' and ch <= 'Z';
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    for (int i = 0; i < maxn; ++i)
        for (auto &row : mp[i]) getline(cin, row);
    vector<string> strs;
    string s;
    getline(cin, s);
    for (int i = 0; i < size(s); ++i) {
        if (!check(s[i])) continue;
        int j = i + 1;
        while (j < size(s) and check(s[j])) ++j;
        strs.push_back(s.substr(i, j - i));
        i = j;
    }
    int n = size(strs);
    for (int i = 0; i < n; ++i) {
        for (int r = 0; r < R; ++r) {
            for (int j = 0; j < size(strs[i]); ++j)
                cout << mp[strs[i][j] - 'A'][r] << (j + 1 < size(strs[i]) ? ' ' : '\n');
        }
        if (i + 1 < n) cout << '\n';
    }
    return 0;
}
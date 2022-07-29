#include <bits/stdc++.h>
using namespace std;

bool check(const char &ch) {
    return isalpha(ch) or isdigit(ch);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s;
    getline(cin, s);
    map<string, int> mp;
    int n = size(s);
    for (int i = 0; i < n; ++i) {
        if (!check(s[i])) continue;
        int j = i;
        string curr;
        while (j < n and check(s[j]))
            curr.push_back(tolower(s[j++]));
        ++mp[curr];
        i = j - 1;
    }
    int cnt = 0;
    for (auto &[str, num] : mp)
        cnt = max(cnt, num);
    for (auto &[str, num] : mp) {
        if (num != cnt) continue;
        s = str;
        break;
    }
    cout << s << ' ' << cnt << '\n';
    return 0;
}
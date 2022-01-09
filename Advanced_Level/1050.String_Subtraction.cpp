#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    cin >> s1 >> s2;
    bitset<128> mp;
    for (auto &ch : s2) mp[ch] = true;
    for (auto &ch : s1)
        if (!mp[ch]) cout << ch;
    cout << '\n';
    return 0;
}
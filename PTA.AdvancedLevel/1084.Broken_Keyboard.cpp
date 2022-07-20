#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s1, s2;
    cin >> s1 >> s2;
    bitset<128> mp;
    for (auto &ch : s2) mp[toupper(ch)] = true;
    for (auto &ch : s1) {
        if (mp[toupper(ch)]) continue;
        cout << char(toupper(ch));
        mp[toupper(ch)] = true;
    }
    cout << '\n';
    return 0;
}
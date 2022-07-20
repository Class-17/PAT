#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> cnt(128);
    string s1, s2;
    cin >> s1 >> s2;
    for (auto &ch : s1) cnt[ch]++;
    auto check = [&]() {
        int pay = 0;
        for (auto &ch : s2)
            if (--cnt[ch] < 0) pay++;
        return pay;
    };
    auto pay = check();
    if (pay) cout << "No " << pay << '\n';
    else     cout << "Yes " << size(s1) - size(s2) << '\n';
    return 0;
}
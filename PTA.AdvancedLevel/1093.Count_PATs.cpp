#include <bits/stdc++.h>
using namespace std;

constexpr int mod = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; cin >> s;
    int p = 0, pa = 0, pat = 0;
    for (auto &ch : s) {
        if (ch == 'P') p = p + 1;
        if (ch == 'A') pa = (pa + p) % mod;
        if (ch == 'T') pat = (pat + pa) % mod;
    }
    cout << pat << endl;
    return 0;
}
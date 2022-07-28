#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    map<int, int> mp;
    for (auto &x : arr) ++mp[x];
    int res = -1;
    for (auto &x : arr) {
        if (res != -1) break;
        if (mp[x] == 1) res = x;
    }
    if (res == -1)
        cout << "None" << '\n';
    else
        cout << res << '\n';
    return 0;
}
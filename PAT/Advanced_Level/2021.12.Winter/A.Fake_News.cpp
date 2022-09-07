#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> res(n);
    for (int i = 0; i < m; ++i) {
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        map<int, int> mp;
        for (auto &x : arr) ++mp[x];
        int t = n;
        for (auto &[_, x] : mp)
            t = min(t, x);
        for (int j = 0; j < n; ++j)
            if (mp[arr[j]] == t) ++res[j];
    }
    cout << max_element(begin(res), end(res)) - begin(res) + 1 << '\n';
    return 0;
}
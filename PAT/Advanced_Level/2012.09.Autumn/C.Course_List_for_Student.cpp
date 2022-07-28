#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    map<string, set<int>> st;
    for (int i = 0; i < k; ++i) {
        int idx, m;
        cin >> idx >> m;
        for (int j = 0; j < m; ++j) {
            string s; cin >> s;
            st[s].insert(idx);
        }
    }
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        cout << s << ' ' << size(st[s]);
        for (auto &x : st[s])
            cout << ' ' << x;
        cout << '\n';
    }
    return 0;
}
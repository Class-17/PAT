#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> es(m);
    for (auto &[u, v] : es) cin >> u >> v;
    int k; cin >> k;
    for (int i = 0; i < k; ++i) {
        int len; cin >> len;
        vector<int> st(n);
        for (int j = 0; j < len; ++j) {
            int v; cin >> v;
            st[v] = 1;
        }
        auto check = [&]() {
            for (auto &[u, v] : es)
                if (!st[u] and !st[v]) return false;
            return true;
        };
        cout << (check() ? "Yes" : "No") << '\n';
    }
    return 0;
}
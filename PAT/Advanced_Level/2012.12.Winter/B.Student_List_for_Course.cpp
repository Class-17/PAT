#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<vector<string>> seq(m);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        int len; cin >> len;
        for (int j = 0; j < len; ++j) {
            int idx; cin >> idx;
            seq[idx - 1].push_back(s);
        }
    }
    for (int i = 0; i < m; ++i) {
        cout << i + 1 << ' ' << size(seq[i]) << '\n';
        sort(begin(seq[i]), end(seq[i]));
        for (auto &s : seq[i])
            cout << s << '\n';
    }
    return 0;
}
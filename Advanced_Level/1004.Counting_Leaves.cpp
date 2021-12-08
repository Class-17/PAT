#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int x, k;
        cin >> x >> k;
        g[x].resize(k);
        for (auto &x : g[x])
            cin >> x;
    }
    queue<int> q;
    q.push(1);
    vector<int> seq;
    while (!q.empty()) {
        int len = size(q);
        int cnt = 0;
        while (len--) {
            auto x = q.front();
            q.pop();
            for (auto &y : g[x])
                q.push(y);
            if (g[x].empty()) cnt++;
        }
        seq.push_back(cnt);
    }
    for (int i = 0; i < size(seq); ++i)
        cout << seq[i] << (i + 1 < size(seq) ? ' ' : '\n');
    return 0;
}
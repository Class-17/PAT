#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map<int, set<int>> g;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        g[u].insert(v);
        g[v].insert(u);
    }
    int k; cin >> k;
    for (int i = 0; i < k; ++i) {
        int u, v;
        cin >> u >> v;
        vector<pair<int, int>> seq;
        if (u * v < 0) {
            for (auto &i : g[u]) {
                if (u * i < 0) continue;
                for (auto &j : g[i]) {
                    if (i * j > 0 or g[j].find(v) == g[j].end()) continue;
                    seq.emplace_back(abs(i), abs(j));
                }
            }
        }
        else {
            for (auto &i : g[u]) {
                if (u * i < 0 or i == v) continue;
                for (auto &j : g[i]) {
                    if (i * j < 0 or j == u or g[j].find(v) == g[j].end()) continue;
                    seq.emplace_back(abs(i), abs(j));
                }
            }
        }
        sort(begin(seq), end(seq));
        cout << size(seq) << '\n';
        for (auto &[u, v] : seq) {
            cout << setw(4) << setfill('0') << u << ' ';
            cout << setw(4) << setfill('0') << v << '\n';
        }   
    }
    return 0;
}
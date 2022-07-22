#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 201;

int g[maxn][maxn];

pair<string, string> check_cycle(vector<int> &seq, int n) {
    vector<int> cnt(n + 1);
    int d = 0;
    for (int i = 0; i + 1 < size(seq); ++i) {
        if (g[seq[i]][seq[i + 1]] == -1) return {"NA", "Not a TS cycle"};
        d += g[seq[i]][seq[i + 1]];
        ++cnt[seq[i + 1]];
    }
    int state = 1;
    for (int i = 1; i <= n; ++i) {
        if (cnt[i] >= 2) state = 0;
        if (cnt[i] == 0) return {to_string(d), "Not a TS cycle"};
    }
    return {to_string(d), (state ? "TS simple cycle" : "TS cycle")};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    memset(g, -1, sizeof g);
    for (int i = 0; i < m; ++i) {
        int a, b, w;
        cin >> a >> b >> w;
        g[a][b] = g[b][a] = w;
    }
    int k; cin >> k;
    int idx, res = INT_MAX;
    for (int i = 1; i <= k; ++i) {
        int len; cin >> len;
        vector<int> seq(len);
        for (auto &x : seq) cin >> x;
        auto [d, s] = check_cycle(seq, n);
        cout << "Path " << i << ": " << d + " (" + s + ")" << '\n';
        if (d != "NA" and s[0] != 'N' and stoi(d) < res)
            tie(idx, res) = pair{i, stoi(d)};
    }
    cout << "Shortest Dist(" << idx << ") = " << res << '\n';
    return 0;
}
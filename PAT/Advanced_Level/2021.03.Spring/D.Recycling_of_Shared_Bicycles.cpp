#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;

constexpr int maxn = 201;

int g[maxn][maxn];

bitset<maxn> st;

int find(int idx, int n) {
    int res = -1;
    for (int i = 0; i <= n; ++i) {
        if (st[i]) continue;
        if (res == -1 or g[idx][i] < g[idx][res])
            res = i;
    }
    if (res == -1 or g[idx][res] == inf) return -1;
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m; 
    cin >> n >> m;
    memset(g, 0x3f, sizeof g);
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    for (int k = 0; k <= n; ++k)
        for (int i = 0; i <= n; ++i)
            for (int j = 0; j <= n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
    vector<int> seq;
    int idx = 0, dist = 0;
    while (true) {
        seq.push_back(idx);
        st[idx] = 1;
        int v = find(idx, n);
        if (v == -1) break;
        dist += g[idx][v];
        idx = v;
    }
    int len = size(seq);
    for (int i = 0; i < len; ++i)
        cout << seq[i] << (i + 1 < len ? ' ' : '\n');
    if (len == n + 1) cout << dist << '\n';
    else {
        seq.clear();
        for (int i = 0; i <= n; ++i)
            if (!st[i]) seq.push_back(i);
        int len = size(seq);
        for (int i = 0; i < len; ++i)
            cout << seq[i] << (i + 1 < len ? ' ' : '\n');
    }
    return 0;
}
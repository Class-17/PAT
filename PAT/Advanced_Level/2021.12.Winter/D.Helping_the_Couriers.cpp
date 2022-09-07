#include <bits/stdc++.h>
using namespace std;

constexpr int inf = 0x3f3f3f3f;

int convert(const string &s) {
    int h = stoi(s.substr(0, 2));
    int m = stoi(s.substr(3, 2));
    return h * 60 + m;
}

string convert(int x) {
    x %= 24 * 60;
    string h = to_string(x / 60);
    string m = to_string(x % 60);
    while (size(h) < 2) h.insert(begin(h), '0');
    while (size(m) < 2) m.insert(begin(m), '0');
    return h + ":" + m;
}

struct node {
    int t, y, p;
    node(int t = inf, int y = 0, int p = 0) : t(t), y(y), p(p) {}
};

vector<vector<int>> g;

vector<node> nodes;

void floyd(int n) {
    for (int k = 0; k < n; ++k)
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    string s; cin >> s;
    int time = convert(s);
    nodes = vector<node>(n + 1);
    for (int i = 1; i <= n; ++i) {
        string t;
        int y, p;
        cin >> t >> y >> p;
        nodes[i] = node(convert(t), y, p);
    }
    g = vector<vector<int>>(n + 1, vector<int>(n + 1, inf));
    for (int i = 0; i <= n; ++i)
        g[i][i] = 0;
    for (int i = 0; i < m; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u][v] = g[v][u] = w;
    }
    floyd(n + 1);
    int k; cin >> k;
    int profit = -inf, finish = inf;
    for (int i = 0; i < k; ++i) {
        vector<int> seq(n + 2);
        seq.front() = seq.back() = 0;
        for (int j = 1; j <= n; ++j)
            cin >> seq[j];
        if (size(set<int>(begin(seq), end(seq))) != n + 1) continue;
        int p = 0, f = time;
        for (int j = 0; j <= n; ++j) {
            int u = seq[j], v = seq[j + 1];
            int cost = g[u][v];
            f += cost;
            p += nodes[v].y;
            if (f > nodes[v].t) p -= nodes[v].p;
        }
        if (p > profit or (p == profit and f < finish))
            tie(profit, finish) = pair{p, f};
    }
    cout << profit << ' ' << convert(finish) << '\n';
    return 0;
}
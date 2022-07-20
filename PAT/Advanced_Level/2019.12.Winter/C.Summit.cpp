#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 200;

bitset<maxn + 1> st[maxn];

bool check(const vector<int> &seq) {
    int n = size(seq);
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (!st[seq[i]][seq[j]]) return false;
    return true;
}

int find(const set<int> &seq, int n) {
    for (int i = 1; i <= n; ++i) {
        if (seq.find(i) != seq.end()) continue;
        int ok = 1;
        for (auto &j : seq) if (!st[i][j]) ok = 0;
        if (ok) return i;
    }
    return 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        st[a][b] = st[b][a] = 1;
    }
    int k; cin >> k;
    for (int i = 1; i <= k; ++i) {
        cout << "Area " << i << ' ';
        int sz; cin >> sz;
        vector<int> seq(sz);
        for (auto &x : seq) cin >> x;
        if (check(seq)) {
            int u = find(set<int>(begin(seq), end(seq)), n);
            if (!u)  cout << "is OK." << '\n';
            else
                cout << "may invite more people, such as " << u << '.' << '\n';
        }
        else
            cout << "needs help." << '\n';
    }
    return 0;
}
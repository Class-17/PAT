#include <bits/stdc++.h>
using namespace std;

constexpr int S = 8 * 60;

constexpr int E = 17 * 60;

string f(int d) {
    if (d == -1) return "Sorry";
    d += S;
    string h = to_string(d / 60);
    string m = to_string(d % 60);
    while (size(h) < 2) h.insert(begin(h), '0');
    while (size(m) < 2) m.insert(begin(m), '0');
    return h + ':' + m;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m, k, q;
    cin >> n >> m >> k >> q;
    vector<int> waits(k), seq(k);
    vector<pair<int, queue<int>>> wds(n);
    for (auto &x : waits) cin >> x;
    int sz = 0;
    auto process = [&]()->void {
        int mint = INT_MAX;
        for (auto &[t, que] : wds)
            if (!que.empty())
                mint = min(mint, t + waits[que.front()]);
        for (auto &[t, que] : wds) {
            if (!que.empty() and t + waits[que.front()] <= mint) {
                if (S + t >= E)
                    seq[que.front()] = -1;
                else
                    seq[que.front()] = t + waits[que.front()];
                t += waits[que.front()];
                que.pop();
                --sz;
            }
        }
    };
    for (int i = 0; i < k; ++i) {
        while (sz >= n * m) process();
        int id = 0;
        for (int i = 1; i < n; ++i)
            if (size(wds[i].second) < size(wds[id].second)) id = i;
        wds[id].second.push(i);
        ++sz;
    }
    while (sz > 0) process();
    for (int i = 0; i < q; ++i) {
        int x; cin >> x;
        cout << f(seq[x - 1]) << '\n';
    }
    return 0;
}
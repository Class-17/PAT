#include <bits/stdc++.h>
using namespace std;

struct info {
    int id, ge, gi;
    vector<int> prefers;
    bool operator < (const info &x) const {
        if (ge + gi == x.ge + x.gi) return ge > x.ge;
        return ge + gi > x.ge + x.gi;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> schools(m);
    for (auto &school : schools) cin >> school;
    vector<info> stus(n);
    for (int i = 0; i < n; ++i) {
        cin >> stus[i].ge >> stus[i].gi;
        stus[i].prefers.resize(k);
        for (auto &x : stus[i].prefers) cin >> x;
        stus[i].id = i;
    }
    sort(begin(stus), end(stus));
    vector<int> mp(n);
    for (int i = 0; i < n; ++i)
        mp[stus[i].id] = i;
    vector<vector<int>> res(m);
    for (int i = 0; i < n; ++i) {
        for (auto &x : stus[i].prefers)
            if (size(res[x]) < schools[x] || 
                stus[mp[res[x].back()]].ge == stus[i].ge &&
                stus[mp[res[x].back()]].gi == stus[i].gi) {
                res[x].push_back(stus[i].id);
                break;
            }
    }
    for (int i = 0; i < m; ++i) {
        sort(begin(res[i]), end(res[i]));
        for (int j = 0; j < size(res[i]); ++j)
            cout << res[i][j] << (j + 1 < size(res[i]) ? ' ' : '\n');
        if (res[i].empty()) cout << '\n';
    }
    return 0;
}
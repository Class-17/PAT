#include <bits/stdc++.h>
using namespace std;

int find(vector<int> &ds, int x) {
    if (ds[x] < 0) return x;
    return ds[x] = find(ds, ds[x]);
}

void unite(vector<int> &ds, int a, int b) {
    a = find(ds, a), b = find(ds, b);
    if (a == b) return;
    if (ds[a] > ds[b]) swap(a, b);
    ds[a] += ds[b];
    ds[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> mp(1001, -1);
    vector<int> ds(n, -1);
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        s.pop_back();
        int len = stoi(s);
        unordered_set<int> group;
        vector<int> h(len);
        for (int j = 0; j < len; ++j) {
            cin >> h[j];
            if (mp[h[j]] == -1) mp[h[j]] = i;
            unite(ds, mp[h[j]], i);
        }
    }
    sort(begin(ds), end(ds));
    int cnt = count_if(begin(ds), end(ds), [](const auto &x){
        return x < 0;
    });
    cout << cnt << endl;
    for (int i = 0; i < cnt; ++i)
        cout << -ds[i] << (i + 1 < cnt ? ' ' : '\n');
    return 0;
}
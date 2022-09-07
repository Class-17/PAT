#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    for (auto &[a, b] : arr)
        cin >> a >> b;
    sort(begin(arr), end(arr));
    queue<pair<int, int>> q;
    q.emplace(0, n);
    vector<int> res;
    auto find = [&](int l, int r) {
        int idx = l;
        while (l < r) {
            if (arr[l].second < arr[idx].second)
                idx = l;
            ++l;
        }
        return idx;
    };
    while (!q.empty()) {
        auto [l, r] = q.front(); q.pop();
        if (l >= r) continue;
        int x = find(l, r);
        res.push_back(x);
        q.emplace(l, x);
        q.emplace(x + 1, r);
    }
    for (int i = 0; i < n; ++i)
        cout << arr[res[i]].first << (i + 1 < n ? ' ' : '\n');
    for (int i = 0; i < n; ++i)
        cout << arr[res[i]].second << (i + 1 < n ? ' ' : '\n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<unordered_set<int>> sets(n);
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        while (m--) {
            int num; cin >> num;
            sets[i].insert(num);
        }
    }
    int k = 0; cin >> k;
    for (int i = 0; i < k; ++i) {
        int a, b; 
        cin >> a >> b;
        int cnt = 0;
        for (auto &num : sets[a - 1])
            if (sets[b - 1].find(num) != sets[b].end()) cnt++;
        int t = size(sets[a - 1]) + size(sets[b - 1]) - cnt;
        cout << setprecision(1) << fixed
             << cnt * 100.0 / t << "%" << '\n';
    }
    return 0;
}
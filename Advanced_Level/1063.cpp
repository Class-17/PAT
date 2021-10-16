#include <bits/stdc++.h>
using namespace std;
int main()
{
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
    auto count_common_numbers = [&](int a, int b) {
        int cnt = 0;
        for (auto & num : sets[a])
            if (sets[b].find(num) != sets[b].end()) cnt++;
        return cnt;
    };
    for (int i = 0; i < k; ++i) {
        int a, b; cin >> a >> b;
        int c = count_common_numbers(a - 1, b - 1);
        int t = sets[a - 1].size() + sets[b - 1].size() - c;
        cout << fixed << std::setprecision(1)
             << c * 100.0 / t << "%" << endl;
    }
    return 0;
}
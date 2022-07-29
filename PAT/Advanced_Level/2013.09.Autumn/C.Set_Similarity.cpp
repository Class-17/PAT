#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<set<int>> arr(n);
    for (int i = 0; i < n; ++i) {
        int m; cin >> m;
        for (int j = 0; j < m; ++j) {
            int x; cin >> x;
            arr[i].insert(x);
        }
    }
    int k; cin >> k;
    auto check = [&](int a, int b) {
        int cnt = 0;
        for (auto &x : arr[b])
            if (arr[a].find(x) == arr[a].end())
                ++cnt;
        int Nc = size(arr[b]) - cnt;
        int Nt = size(arr[a]) + size(arr[b]) - Nc;
        return pair{Nc, Nt};
    };
    for (int i = 0; i < k; ++i) {
        int a, b;
        cin >> a >> b;
        auto [Nc, Nt] = check(a - 1, b - 1);
        cout << setprecision(1) << fixed << Nc * 100.0 / Nt << "%\n";
    }
    return 0;
}
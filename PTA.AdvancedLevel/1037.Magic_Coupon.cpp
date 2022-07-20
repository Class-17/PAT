#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    int m; cin >> m;
    vector<int> b(m);
    for (auto &x : b) cin >> x;
    sort(begin(a), end(a));
    sort(begin(b), end(b));
    auto count = [&](int i, int j, int d) {
        int sum = 0;
        while (i >= 0 && i < n && j >= 0 && j < m && a[i] * d < 0 && a[i] * b[j] > 0) {
            sum += a[i] * b[j];
            i += d; j += d;
        }
        return sum;
    };
    cout << count(0, 0, 1) + count(n - 1, m - 1, -1) << '\n';
    return 0;
}
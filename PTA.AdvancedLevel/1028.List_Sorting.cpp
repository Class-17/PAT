#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, c;
    cin >> n >> c;
    vector<vector<string>> data(n, vector<string>(3));
    for (int i = 0; i < n; ++i)
        for (auto &x : data[i]) cin >> x;
    sort(data.begin(), data.end(), [&](const auto &a, const auto &b) {
        if (a[c - 1] == b[c - 1]) return a[0] < b[0];
        if (c == 3) return stoi(a[2]) < stoi(b[2]);
        return a[c - 1] < b[c - 1];
    });
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            cout << data[i][j] << (j < 2 ? ' ' : '\n');
    return 0;
}
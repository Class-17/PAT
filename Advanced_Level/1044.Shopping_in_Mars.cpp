#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> seq(n + 1);
    for (int i = 1; i < size(seq); i++) {
        cin >> seq[i];
        seq[i] += seq[i - 1];
    }
    vector<pair<int, int>> res;
    int min_pay = INT_MAX;
    for (int i = 1; i < seq.size(); i++) {
        int j = lower_bound(begin(seq) + i, end(seq), seq[i - 1] + m) - begin(seq);
        if (j == n + 1) continue;
        if (seq[j] - seq[i - 1] == min_pay)
            res.emplace_back(i, j);
        else if (seq[j] - seq[i - 1] < min_pay) {
            min_pay = seq[j] - seq[i - 1];
            res.clear();
            res.emplace_back(i, j);
        }
    }
    for (auto &[x, y] : res)
        cout << x << '-' << y << '\n';
    return 0;
}
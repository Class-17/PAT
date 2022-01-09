#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> seq(n);
    for (auto& x : seq) cin >> x;
    sort(begin(seq), end(seq));
    auto find = [&]()->string {
        for (int i = 0; i < n; ++i) {
            int j = lower_bound(begin(seq) + i + 1, end(seq), m - seq[i]) - begin(seq);
            if (j != n && seq[j] + seq[i] == m)
                return to_string(seq[i]) + ' ' + to_string(seq[j]);
        }
        return "No Solution";
    };
    cout << find() << '\n';
    return 0;
}
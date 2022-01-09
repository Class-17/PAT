#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> seq(n);
    for (auto &x : seq) cin >> x;
    vector<pair<int, int>> rec(n);
    int left_max = 0, right_min = INT_MAX;
    for (int i = 0; i < n; ++i) {
        rec[i].first = left_max;
        left_max = max(seq[i], left_max);
    }
    for (int i = n - 1; i >= 0; --i) {
        rec[i].second = right_min;
        right_min = min(seq[i], right_min);
    }
    vector<int> ans;
    for (int i = 0; i < seq.size(); ++i)
        if (seq[i] > rec[i].first && seq[i] < rec[i].second)
            ans.push_back(seq[i]);
    cout << size(ans) << '\n';
    for (int i = 0; i < size(ans); ++i)
        cout << ans[i] << (i + 1 < size(ans) ? ' ' : '\0');
    cout << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; ++i) {
        int ptr, len;
        cin >> ptr >> len;
        for (int j = 0; j < len; ++j) {
            arr.emplace_back(ptr + j * 4, i);
        }
    }
    int sz = 0;
    for (int i = 0; i < k; ++i) {
        int idx; cin >> idx;
        if (idx >= size(arr))
            cout << "Illegal Access" << '\n';
        else {
            cout << arr[idx].first << '\n';
            sz = max(sz, arr[idx].second);
        }
    }
    cout << sz + 1 << '\n';
    return 0;
}
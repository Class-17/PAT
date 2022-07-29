#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(begin(arr), end(arr));
    auto solve = [&]()->string {
        for (int i = 0; i < n; ++i) {
            auto p = lower_bound(begin(arr) + i + 1, end(arr), m - arr[i]);
            if (p != end(arr) and *p + arr[i] == m)
                return to_string(arr[i]) + ' ' + to_string(*p);
        }
        return "No Solution";
    };
    cout << solve() << '\n';
    return 0;
}
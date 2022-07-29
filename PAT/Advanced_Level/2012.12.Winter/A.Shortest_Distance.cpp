#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    partial_sum(begin(arr), end(arr), begin(arr));
    int sum = arr.back();
    int m; cin >> m;
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        if (a > b) swap(a, b);
        int dist = arr[b - 2] - (a - 1 ? arr[a - 2] : 0);
        cout << min(dist, sum - dist) << '\n';
    }
    return 0;
}
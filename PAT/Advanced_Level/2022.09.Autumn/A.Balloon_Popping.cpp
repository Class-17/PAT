#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, h;
    cin >> n >> h;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    int idx = -1, len = 1;
    for (int i = n - 1; i >= 0; --i) {
        int p = lower_bound(begin(arr), end(arr), arr[i] - h) - begin(arr);
        if (i - p + 1 >= len)
            tie(idx, len) = pair{arr[i] - h, i - p + 1};
    }
    cout << idx << ' ' << len << '\n';
    return 0;
}
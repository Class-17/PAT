#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (auto &x : arr) cin >> x;
        vector<int> left(n, INT_MIN), right(n, INT_MAX);
        for (int i = 1; i < n; ++i)
            left[i] = max(arr[i - 1], left[i - 1]);
        for (int i = n - 2; i >= 0; --i)
            right[i] = min(arr[i + 1], right[i + 1]);
        int count = 0;
        for (int i = 0; i < n; ++i)
            if (left[i] < arr[i] and arr[i] < right[i]) {
                if (i == 0 or i == n - 1) ++count;
                count++;   
            }
        cout << (count >= 3 ? "Yes" : "No") << '\n';
    }
    return 0;
}
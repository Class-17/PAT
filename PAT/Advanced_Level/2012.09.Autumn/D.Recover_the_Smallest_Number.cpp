#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<string> nums(n);
    for (auto &x : nums) cin >> x;
    sort(begin(nums), end(nums), [&](const auto &a, const auto &b) {
        return a + b < b + a;
    });
    string res;
    for (auto &x : nums)
        res += x;
    int i = 0;
    while (i + 1 < size(res) and res[i] == '0') ++i;
    res.erase(begin(res), begin(res) + i);
    cout << res << '\n';
    return 0;
}
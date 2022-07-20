#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<pair<char, double>> res;
    for (int i = 0; i < 3; ++i) {
        vector<double> arr(3);
        for (auto &x : arr) cin >> x;
        int p = max_element(begin(arr), end(arr)) - begin(arr);
        if (p == 0) res.emplace_back('W', arr[p]);
        else if (p == 1) res.emplace_back('T', arr[p]);
        else             res.emplace_back('L', arr[p]);
    }
    double val = 1.0;
    for (auto &[ch, v] : res) {
        val *= v;
        cout << ch << ' ';
    }
    cout << setprecision(2) << fixed << (val * 0.65 - 1) * 2 << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> seq(n);
    for (auto &x : seq) cin >> x;
    vector<int> mp(1e4 + 1);
    for (auto &x : seq) mp[x]++;
    auto find_x = [&]()->string {
        for (auto &x : seq)
            if (mp[x] == 1) return to_string(x);
        return "None";
    };
    cout << find_x() << '\n';
    return 0;
}
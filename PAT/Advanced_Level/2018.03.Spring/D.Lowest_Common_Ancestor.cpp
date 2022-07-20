#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    unordered_map<int, bool> mp;
    vector<int> seq(n);
    for (int i = 0; i < n; ++i) {
        cin >> seq[i];
        mp[seq[i]] = true;
    }
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        auto search = [&]() {
            for (int i = 0; i < n; ++i)
                if (seq[i] >= a && seq[i] <= b || 
                    seq[i] >= b && seq[i] <= a) return seq[i];
            return -1;
        };
        int res = search();
        if (!mp[a] && !mp[b])
            cout << "ERROR: " << a << " and " << b << " are not found.\n";
        else if (!mp[a] || !mp[b])
            cout << "ERROR: " << (mp[a] ? b : a) << " is not found.\n";
        else if (res == a || res == b)
            cout << res << " is an ancestor of " << (res == a ? b : a) << ".\n";
        else
            cout << "LCA of " << a << " and " << b << " is " << res << ".\n";
    }
    return 0;
}
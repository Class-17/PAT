#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<int> arr(m);
    for (auto &x : arr) cin >> x;
    set<pair<int, int>> st;
    map<int, int> mp;
    vector<int> res;
    for (int i = 0; i < m; ++i) {
        if (mp.find(arr[i]) != mp.end())
            st.erase({mp[arr[i]], arr[i]});
        mp[arr[i]] = i;
        st.emplace(i, arr[i]);
        if (size(st) > n) {
            int x = begin(st)->second;
            res.push_back(x);
            mp.erase(x);
            st.erase(begin(st));
        }
    }
    int len = size(res);
    for (int i = 0; i < len; ++i)
        cout << res[i] << (i + 1 < len ? ' ' : '\n');
    return 0;
}
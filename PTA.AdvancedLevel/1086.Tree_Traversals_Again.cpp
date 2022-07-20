#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> pre, in, st, post;
    for (int i = 0; i < n * 2; ++i) {
        string op;
        cin >> op;
        if (op[1] == 'u') {
            int x; cin >> x;
            pre.push_back(x);
            st.push_back(x);
        }
        else {
            in.push_back(st.back());
            st.pop_back();
        }
    }
    unordered_map<int, int> mp(n);
    for (int i = 0; i < n; ++i)
        mp[in[i]] = i;
    auto dfs = [&](auto &dfs, int a, int b, int c, int d)->void {
        if (b - a <= 0) return;
        int root = pre[a];
        dfs(dfs, a + 1, a + mp[root] - c + 1, c, mp[root]);
        dfs(dfs, a + (mp[root] - c) + 1, b, mp[root] + 1, d);
        post.push_back(root);
    };
    dfs(dfs, 0, n, 0, n);
    for (int i = 0; i < n; ++i)
        cout << post[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
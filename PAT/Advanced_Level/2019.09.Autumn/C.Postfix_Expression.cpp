#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 20;

struct node {
    string val;
    int l, r;
} tree[maxn + 1];

string dfs(int idx) {
    auto &[val, l, r] = tree[idx];
    string a = (l > 0 ? dfs(l) : "");
    string b = (r > 0 ? dfs(r) : "");
    if (a.empty() or b.empty()) return "(" + val + a + b + ")";
    return "(" + a + b + val + ")";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> de(n + 1);
    for (int i = 1; i <= n; ++i) {
        auto &[val, l, r] = tree[i];
        cin >> val >> l >> r;
        if (l > 0) ++de[l];
        if (r > 0) ++de[r];
    }
    int root = 0;
    for (int i = 1; i <= n and !root; ++i)
        if (!de[i]) root = i;
    cout << dfs(root) << '\n';
    return 0;
}
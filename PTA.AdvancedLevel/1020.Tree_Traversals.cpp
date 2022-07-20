#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
    node(int x = 0, node *left = nullptr, node *right = nullptr) : 
        val(x), left(left), right(right) {}
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> post(n), in(n);
    for (auto &x : post) cin >> x;
    for (auto &x : in) cin >> x;
    unordered_map<int, int> mp(n);
    for (int i = 0; i < n; ++i)
        mp[in[i]] = i;
    auto dfs = [&](auto &dfs, int a, int b, int c, int d)->node* {
        if (b - a <= 0) return nullptr;
        int root = post[b - 1];
        auto tree = new node(root);
        tree->left = dfs(dfs, a, a + mp[root] - c, c, mp[root]);
        tree->right = dfs(dfs, a + (mp[root] - c), b - 1, mp[root] + 1, d);
        return tree;
    };
    auto tree = dfs(dfs, 0, n, 0, n);
    queue<node*> q;
    q.push(tree);
    vector<int> seq;
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        seq.push_back(x->val);
        if (x->left) q.push(x->left);
        if (x->right) q.push(x->right);
    }
    for (int i = 0; i < n; ++i)
        cout << seq[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
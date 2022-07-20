#include <bits/stdc++.h>
using namespace std;

int find_root(vector<pair<int, int>> &tree) {
    vector<bool> memo(size(tree));
    for (auto &[l, r] : tree) {
        if (l != -1) memo[l] = true;
        if (r != -1) memo[r] = true;
    }
    for (int i = 0; i < size(tree); ++i)
        if (!memo[i]) return i;
    return -1;
};

void invert(vector<pair<int, int>> &tree, int x) {
    if (x == -1) return;
    invert(tree, tree[x].first);
    invert(tree, tree[x].second);
    swap(tree[x].first, tree[x].second);
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> tree(n);
    for (int i = 0; i < n; ++i) {
        string a, b;
        cin >> a >> b;
        tree[i].first = (a != "-" ? stoi(a) : -1);
        tree[i].second = (b != "-" ? stoi(b) : -1);
    }
    int root = find_root(tree);
    invert(tree, root);
    vector<int> pre, in;
    queue<int> q;
    q.push(root);
    while (!q.empty()) {
        auto x = q.front();
        q.pop();
        pre.push_back(x);
        if (tree[x].first != -1) 
            q.push(tree[x].first);
        if (tree[x].second != -1)
            q.push(tree[x].second);
    }
    auto dfs = [&](auto &dfs, int x) {
        if (x == -1) return;
        dfs(dfs, tree[x].first);
        in.push_back(x);
        dfs(dfs, tree[x].second);
    };
    dfs(dfs, root);
    for (int i = 0; i < n; ++i)
        cout << pre[i] << (i + 1 < n ? ' ' : '\n');
    for (int i = 0; i < n; ++i)
        cout << in[i] << (i + 1 < n ? ' ' : '\n');        
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct node {
    int val;
    node *left, *right;
    node (int x) : val(x), left(nullptr), right(nullptr) {}
};

bool cmp1(int a, int b) {
    return a < b;
}

bool cmp2(int a, int b) {
    return a >= b;
}

node *insert(node *x, int val, bool cmp(int a, int b)) {
    if (x == nullptr)
        return new node(val);
    if (cmp(val, x->val))
        x->left = insert(x->left, val, cmp);
    else
        x->right = insert(x->right, val, cmp);
    return x;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> seq(n);
    for (auto &x : seq) cin >> x;
    node * tree = new node(seq[0]);
    for (int i = 1; i < n; ++i)
        insert(tree, seq[i], (seq[0] > seq[1] ? cmp1 : cmp2));
    vector<int> res;
    auto dfs = [&](auto &dfs, node *x, int order) {
        if (x == nullptr) return;
        if (order == 1)
            res.push_back(x->val);
        dfs(dfs, x->left, order);
        dfs(dfs, x->right, order);
        if (order == 2)
            res.push_back(x->val);
    };
    dfs(dfs, tree, 1);
    if (res == seq) {
        cout << "YES" << endl;
        res.clear();
        dfs(dfs, tree, 2);
        for (int i = 0; i < n; ++i)
            cout << res[i] << (i + 1 < n ? ' ': '\n');
    }
    else
        cout << "NO" << endl;
    return 0;
}
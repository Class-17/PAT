#include <bits/stdc++.h>
using namespace std;

struct tree {
    int val;
    tree *left, *right;
    tree(int val = 0, tree *left = nullptr, tree *right = nullptr) :
        val(val), left(left), right(right) {}
};

vector<int> inO, preO;

map<int, int> mp;

tree *build(int iL, int iR, int pL, int pR) {
    if (iR - iL < 1) return nullptr;
    int root = mp[preO[pL]];
    tree *t = new tree(preO[pL]);
    int len = root - iL;
    t->left = build(iL, root, pL + 1, pL + 1 + len);
    t->right = build(root + 1, iR, pL + 1 + len, pR);
    return t;
}

int check_type(tree *root, int n) {
    int level = 0;
    while (pow(2, level + 1) - 1 <= n) ++level;
    queue<tree*> q;
    q.push(root);
    vector<tree*> res;
    res.push_back(root);
    int tot = 1, curr = 0;
    while (!q.empty() and curr < level) {
        int len = size(q);
        while (len--) {
            auto x = q.front(); q.pop();
            if (x->left) q.push(x->left);
            if (x->right) q.push(x->right);
            if (curr + 1 < level and (!x->left or !x->right)) return 0;
            tot += (x->left != nullptr) + (x->right != nullptr);
            res.push_back(x->left);
            res.push_back(x->right);
        }
        ++curr;
    }
    if (q.empty()) return 1;
    while (!q.empty()) {
        auto x = q.front(); q.pop();
        if (x->left) return 0;
        if (x->right) return 0;
    }
    for (auto &x : res) {
        if (tot == 0) break;
        if (x) --tot;
        else   return 3;
    }
    return 2;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    inO = preO = vector<int>(n);
    for (auto &x : inO) cin >> x;
    for (auto &x : preO) cin >> x;
    for (int i = 0; i < n; ++i)
        mp[inO[i]] = i;
    auto t = build(0, n, 0, n);
    vector<int> res;
    auto dfs = [&](auto &dfs, tree *root) {
        if (!root) return;
        dfs(dfs, root->left);
        dfs(dfs, root->right);
        res.push_back(root->val);
    };
    dfs(dfs, t);
    cout << check_type(t, n) << '\n';
    for (int i = 0; i < n; ++i)
        cout << res[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
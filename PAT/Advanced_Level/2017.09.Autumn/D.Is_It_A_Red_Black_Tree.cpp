#include <bits/stdc++.h>
using namespace std;

class tree {
public:
    int val;
    tree *left, *right;
    tree(int val) : val(val), left(nullptr), right(nullptr) {};
};

vector<int> preO, inO;

tree *build(int pL, int pR, int iL, int iR) {
    if (pR - pL < 1) return nullptr;
    int root = iL;
    while (root < iR and inO[root] != preO[pL]) ++root;
    int len = root - iL;
    if (root == iR) return nullptr;
    auto t = new tree(inO[root]);
    t->left = build(pL + 1, pL + 1 + len, iL, root);
    t->right = build(pL + 1 + len, pR, root + 1, iR);
    return t;
}

tree *insert(tree *t, int x) {
    if (t == nullptr)
        return new tree(x);
    if (abs(x) < abs(t->val))
        t->left = insert(t->left, x);
    if (abs(x) > abs(t->val))
        t->right = insert(t->right, x);
    return t;
}

void deleteTree(tree *t) {
    if (t == nullptr) return;
    deleteTree(t->left);
    deleteTree(t->right);
    delete t;
}

int dfs(tree *t) {
    if (t == nullptr) return 1;
    if (t->val < 0) {
        if (t->left and t->left->val < 0) return 0;
        if (t->right and t->right->val < 0) return 0;
    }
    int l = dfs(t->left), r = dfs(t->right);
    if (!l or !r or l != r) return 0;
    return l + (t->val > 0);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int n; cin >> n;
        preO = vector<int>(n);
        for (auto &x : preO) cin >> x;
        inO = preO;
        sort(begin(inO), end(inO), [&](const auto &a, const auto &b) {
            return abs(a) < abs(b);});
        auto t = build(0, n, 0, n);
        cout << (min(dfs(t), t->val) > 0 ? "Yes" : "No") << '\n';
        deleteTree(t);
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class tree {
public:
    int val;
    tree *left, *right;

    tree(int val) : val(val), left(nullptr), right(nullptr) {}
};

vector<int> preO, inO, postO;

map<int, int> mp;

tree *build(int pL, int pR, int iL, int iR) {
    if (iR - iL < 1) return nullptr;
    int root = mp[preO[pL]];
    int len = root - iL;
    auto t = new tree(inO[root]);
    t->left = build(pL + 1, pL + 1 + len, iL, root);
    t->right = build(pL + 1 + len, pR, root + 1, iR);
    return t;
}

void dfs(tree *t) {
    if (t == nullptr) return;
    dfs(t->left);
    dfs(t->right);
    postO.push_back(t->val);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    preO = inO = vector<int>(n);
    for (auto &x : preO) cin >> x;
    for (auto &x : inO) cin >> x;
    for (int i = 0; i < n; ++i)
        mp[inO[i]] = i;
    auto t = build(0, n, 0, n);
    dfs(t);
    cout << postO.front() << '\n';
    return 0;
}
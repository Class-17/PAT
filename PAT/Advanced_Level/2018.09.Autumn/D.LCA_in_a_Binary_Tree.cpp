#include <bits/stdc++.h>
using namespace std;

struct tree {
    tree *l, *r;
    int val;
    tree(int val) : val(val), l(nullptr), r(nullptr) {}
};

vector<int> in, pre;

tree *build(int iL, int iR, int pL, int pR) {
    if (iL == iR) return nullptr;
    auto find = [&]() {
        for (int i = iL; i < iR; ++i)
            if (in[i] == pre[pL]) return i;
        return -1;
    };
    int root = find();
    auto t = new tree(in[root]);
    t->l = build(iL, root, pL + 1, pL + 1 + root - iL);
    t->r = build(root + 1, iR, pL + 1 + root - iL, pR);
    return t;
}

tree *lca(tree *t, int u, int v) {
    if (!t) return nullptr;
    auto left = lca(t->l, u, v);
    auto right = lca(t->r, u, v);
    if (t->val == u or t->val == v) return t;
    if (left and right) return t;
    if (left) return left;
    if (right) return right;
    return nullptr;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n;
    cin >> m >> n;
    in = pre = vector<int>(n);
    for (auto &x : in) cin >> x;
    for (auto &x : pre) cin >> x;
    set<int> st(begin(in), end(in));
    auto t = build(0, n, 0, n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        auto check = [&]() {
            int s1 = (st.find(u) != st.end());
            int s2 = (st.find(v) != st.end());
            if (!s1 and !s2)
                cout << "ERROR: " << u << " and " << v << " are not found." << '\n';
            else if (!s1 and s2)
                cout << "ERROR: " << u << " is not found." << '\n';
            else if (s1 and !s2)
                cout << "ERROR: " << v << " is not found." << '\n';
            return s1 and s2;
        };
        if (!check()) continue;
        auto res = lca(t, u, v);
        if (res->val == u)
            cout << u << " is an ancestor of " << v << ".\n";
        else if (res->val == v)
            cout << v << " is an ancestor of " << u << ".\n";
        else
            cout << "LCA of " << u << " and " << v << " is " << res->val << ".\n";
    }
    return 0;
}
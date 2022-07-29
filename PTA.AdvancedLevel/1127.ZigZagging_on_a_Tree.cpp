#include <bits/stdc++.h>
using namespace std;

class tree {
public:
    int val;
    tree *left, *right;
    tree(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inO, postO;

tree *build(int inL, int inR, int postL, int postR) {
    if (postR - postL < 1) return nullptr;
    int root = inL;
    while (root < inR and inO[root] != postO[postR - 1]) ++root;
    int len = root - inL;
    auto t = new tree(inO[root]);
    t->left = build(inL, root, postL, postL + len);
    t->right = build(root + 1, inR, postL + len, postR - 1);
    return t;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    inO = postO = vector<int>(n);
    for (auto &x : inO) cin >> x;
    for (auto &x : postO) cin >> x;
    auto t = build(0, n, 0, n);
    queue<tree*> q;
    q.push(t);
    vector<int> seq;
    int round = 0;
    while (!q.empty()) {
        int sz = size(q);
        vector<int> curr;
        while (sz--) {
            auto x = q.front(); q.pop();
            curr.push_back(x->val);
            if (x->left) q.push(x->left);
            if (x->right) q.push(x->right);
        }
        if (round == 0)
            reverse(begin(curr), end(curr));
        for (auto &x : curr)
            seq.push_back(x);
        round ^= 1;
    }
    for (int i = 0; i < n; ++i)
        cout << seq[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
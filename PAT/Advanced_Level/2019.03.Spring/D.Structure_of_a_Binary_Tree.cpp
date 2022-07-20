#include <bits/stdc++.h>
using namespace std;

vector<int> inO, posO;

struct tree {
    tree *l, *r;
    int val;
    tree(int val, tree *l = nullptr, tree *r = nullptr) : val(val) {}
};

int find(int val, int l, int r) {
    for (int i = l; i < r; ++i)
        if (inO[i] == val) return i;
    return -1;
}

tree *build(int pL, int pR, int iL, int iR) {
    if (pR - pL < 1) return nullptr;
    int root = pR - 1;
    tree *t = new tree(posO[root]);
    int mid = find(posO[root], iL, iR);
    t->l = build(pL, pL + mid - iL, iL, mid);
    t->r = build(pL + mid - iL, pR - 1, mid + 1, iR);
    return t;
}

int dfs(tree *t, int val) {
    if (!t) return 0;
    if (t->val == val) return 1;
    auto left = dfs(t->l, val);
    auto right = dfs(t->r, val);
    if (left) return left + 1;
    if (right) return right + 1;
    return 0; 
}

int get_num(const string &s, int p) {
    int val = 0;
    for (int i = p; i < size(s) and isdigit(s[i]); ++i)
        val = val * 10 + s[i] - '0';
    return val;
}

tree *get_pa(tree *t, int val) {
    if (!t) return nullptr;
    if (t->l and t->l->val == val) return t;
    if (t->r and t->r->val == val) return t;
    auto left = get_pa(t->l, val);
    auto right = get_pa(t->r, val);
    return left ? left : right;
}

tree *get(tree *t, int val) {
    if (!t) return nullptr;
    if (t->val == val) return t;
    auto left = get(t->l, val);
    auto right = get(t->r, val);
    return left ? left : right;
}

bool check(tree *t) {
    if (!t) return true;
    if (t->l and !t->r) return false;
    if (!t->l and t->r) return false;
    return check(t->l) and check(t->r);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    posO = inO = vector<int>(n);
    for (auto &x : posO) cin >> x;
    for (auto &x : inO) cin >> x;
    tree *t = build(0, n, 0, n);
    int m; (cin >> m).get();
    for (int i = 0; i < m; ++i) {
        string s; getline(cin, s);
        if (s.find("root") != string::npos) {
            int r = get_num(s, 0);
            cout << (r == t->val ? "Yes" : "No") << '\n';
        }
        else if (s.find("siblings") != string::npos) {
            int a = get_num(s, 0), b = get_num(s, s.find("and") + 4);
            auto pa = get_pa(t, a), pb = get_pa(t, b);
            cout << (pa == pb and a != b ? "Yes" : "No") << '\n';
        }
        else if (s.find("parent") != string::npos) {
            int p = get_num(s, 0), son = get_num(s, s.find("of") + 3);
            auto ptr = get_pa(t, son);
            cout << (ptr and ptr->val == p ? "Yes" : "No") << '\n';
        }
        else if (s.find("left") != string::npos) {
            int son = get_num(s, 0), p = get_num(s, s.find("of") + 3);
            auto ptr = get(t, p);
            cout << (ptr->l and ptr->l->val == son ? "Yes" : "No") << '\n';
        }
        else if (s.find("right") != string::npos) {
            int son = get_num(s, 0), p = get_num(s, s.find("of") + 3);
            auto ptr = get(t, p);
            cout << (ptr->r and ptr->r->val == son ? "Yes" : "No") << '\n';
        }
        else if (s.find("level") != string::npos) {
            int a = get_num(s, 0), b = get_num(s, s.find("and") + 4);
            cout << (dfs(t, a) == dfs(t, b) ? "Yes" : "No") << '\n';
        }
        else {
            cout << (check(t) ? "Yes" : "No") << '\n';
        }
    }
    return 0;
}
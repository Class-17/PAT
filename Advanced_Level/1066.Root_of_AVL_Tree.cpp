#include <bits/stdc++.h>
using namespace std;

struct node {
    int val, h;
    node *left, *right;
    node (int val) : val(val), h(0), left(nullptr), right(nullptr) {}
};

int get_h(node *tree) {
    return tree ? tree->h : -1;
}

node *left_rotation(node *tree) {
    node *new_tree = tree->left;
    tree->left = new_tree->right;
    new_tree->right = tree;
    tree->h = max(get_h(tree->left), get_h(tree->right)) + 1;
    new_tree->h = max(get_h(new_tree->left), get_h(new_tree->right)) + 1;
    return new_tree;
}

node *right_rotation(node *tree) {
    node *new_tree = tree->right;
    tree->right = new_tree->left;
    new_tree->left = tree;
    tree->h = max(get_h(tree->left), get_h(tree->right)) + 1;
    new_tree->h = max(get_h(new_tree->left), get_h(new_tree->right)) + 1;
    return new_tree;
}

node *insert(node *tree, int val) {
    if (tree == nullptr) return new node(val);
    if (val < tree->val) {
        tree->left = insert(tree->left, val);
        if (get_h(tree->left) - get_h(tree->right) == 2) {
            if (val > tree->left->val)
                tree->left = right_rotation(tree->left);
            tree = left_rotation(tree);
        }     
    }
    else {
        tree->right = insert(tree->right, val);
        if (get_h(tree->right) - get_h(tree->left) == 2) {
            if (val < tree->right->val)
                tree->right = left_rotation(tree->right);
            tree = right_rotation(tree);
        }
    }
    tree->h = max(get_h(tree->left), get_h(tree->right)) + 1;
    return tree;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    node *tree = nullptr;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        tree = insert(tree, x);
    }
    cout << tree->val << endl;
    return 0;
}
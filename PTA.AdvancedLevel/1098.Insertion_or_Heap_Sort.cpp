#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    auto find_inorder = [&]() {
        for (int i = 1; i < n; ++i)
            if (b[i] < b[i - 1]) return i;
        return n;
    };
    auto check = [&](int p) {
        for (int i = p; i < n; ++i)
            if (a[i] != b[i]) return false;
        return true;
    };
    int p = find_inorder();
    if (check(p)) {
        cout << "Insertion Sort" << endl;
        sort(begin(b), begin(b) + min(p + 1, n));
    }
    else {
        cout << "Heap Sort" << endl;
        auto find_back_order = [&]() {
            for (int i = n - 1; i > 0; --i)
                if (b[i] < b[i - 1])
                    return i;
            return 0;
        };
        auto heap_sort = [&](int p) {
            swap(b[0], b[p--]);
            int i = 0;
            while (i * 2 + 1 <= p) {
                int t = i * 2 + 1;
                if (i * 2 + 2 <= p && b[i * 2 + 2] > b[t]) t++;
                if (b[i] > b[t]) break;
                swap(b[i], b[t]);
                i = t;
            }   
        };
        heap_sort(find_back_order());
    }
    for (int i = 0; i < n; ++i)
        cout << b[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
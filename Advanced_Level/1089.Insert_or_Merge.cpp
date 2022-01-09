#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    auto check = [&]() {
        int p = 1;
        while (p < n && b[p] >= b[p - 1]) p++;
        for (int i = p; i < n; ++i)
            if (a[i] != b[i]) return false;
        sort(begin(a), begin(a) + p + 1);
        return true;
    };
    auto merge = [&]() {
        bool sort_ok = false;
        for(int i = 2; i / 2 < n; i *= 2) {
            for(int j = 0; j < n; j += i)
                sort(begin(a) + j, begin(a) + min(j + i, n));
            if (sort_ok) return true;
            sort_ok = (a == b);
        }
        return false;
    };
    if (check()) 
        cout << "Insertion Sort\n";
    else if (merge())
        cout << "Merge Sort\n";
    for(int i = 0; i < n; i++)
        cout << a[i] << (i + 1 < n ? ' ' : '\n'); 
    return 0;
}
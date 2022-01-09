#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> a(n); 
    for (auto &x : a) cin >> x;
    int m; cin >> m;
    vector<int> b(m); 
    for (auto &x : b) cin >> x;
    int i = 0, j = 0, p = 0, median = 0;
    while (p <= (n + m - 1) / 2) {
        if (i < n && j < m) {
            if (a[i] < b[j]) median = a[i++];
            else            median = b[j++];
        }
        else if (i < n) median = a[i++];
        else if (j < m) median = b[j++];
        p++;
    }
    cout << median << '\n';
    return 0;
}
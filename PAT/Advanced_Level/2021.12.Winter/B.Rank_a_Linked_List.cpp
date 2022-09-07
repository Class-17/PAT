#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    vector<int> de(n);
    for (auto &x : arr)
        if (x >= 0) ++de[x];
    int ptr = -1;
    for (int i = 0; i < n; ++i)
        if (!de[i]) ptr = i;
    map<int, int> mp;
    int rank = 1;
    while (ptr != -1) {
        mp[ptr] = rank++;
        ptr = arr[ptr];
    }
    for (int i = 0; i < n; ++i)
        cout << mp[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
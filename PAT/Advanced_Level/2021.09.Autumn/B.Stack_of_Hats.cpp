#include <bits/stdc++.h>
using namespace std;

vector<int> transe(const vector<int>& arr, int n) {
    vector<int> id(n);
    iota(begin(id), end(id), 0);
    sort(begin(id), end(id), [&](const auto &a, const auto &b) {
        return arr[a] < arr[b];
    });
    return id;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    auto rankA = transe(a, n);
    auto rankB = transe(b, n);
    vector<int> res(n);
    for (int i = 0; i < n; ++i)
        res[rankA[i]] = i;
    for (int i = n - 1; i >= 0; --i)
        cout << rankB[res[i]] + 1 << (i > 0 ? ' ' : '\n');   
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> arr[i];
    vector<vector<int>> seqs;
    vector<int> seq;
    auto dfs = [&](auto &dfs, int u)->void {
        seq.push_back(arr[u]);
        if (u * 2 > n) seqs.push_back(seq);
        if (u * 2 <= n)     dfs(dfs, u * 2);
        if (u * 2 + 1 <= n) dfs(dfs, u * 2 + 1);
        seq.pop_back();
    };
    dfs(dfs, 1);
    reverse(begin(seqs), end(seqs));
    int a = 0, b = 0, c = 0;
    for (auto &seq : seqs) {
        for (int i = 0; i < size(seq); ++i)
            cout << seq[i] << (i + 1 < size(seq) ? ' ' : '\n');
        auto temp = seq;
        reverse(begin(temp), end(temp));
        if (is_sorted(begin(seq), end(seq)))        ++a;
        else if (is_sorted(begin(temp), end(temp))) ++b;
        else                                        ++c;
    }
    if (!a and b and !c)      cout << "Max Heap" << '\n';
    else if (a and !b and !c) cout << "Min Heap" << '\n';
    else                      cout << "Not Heap" << '\n';
    return 0;
}
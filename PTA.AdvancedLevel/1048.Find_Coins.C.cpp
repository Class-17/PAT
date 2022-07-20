#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> seq(n);
    for (auto& x : seq) cin >> x;
    sort(begin(seq), end(seq));
    auto find = [&]()->string {
        int lo = 0, hi = n - 1;
        while (lo < hi) {
            if (seq[lo] + seq[hi] == m)
                return to_string(seq[lo]) + ' ' + to_string(seq[hi]);
            if (seq[lo] + seq[hi] < m) lo++;
            else                           hi--; 
        }
        return "No Solution";
    };
    cout << find() << '\n';
    return 0;
}
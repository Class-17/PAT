#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> cnt(1001);
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        cnt[x]++;
    }
    auto find = [&]()->string {
        for (int i = 0; i <= m / 2; ++i)
            if (i * 2 == m && cnt[i] > 1 || i * 2 != m && cnt[i] && cnt[m - i])
                return to_string(i) + ' ' + to_string(m - i);
        return "No Solution";
    };
    cout << find() << '\n';
    return 0;
}
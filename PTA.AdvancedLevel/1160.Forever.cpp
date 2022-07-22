#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 10;

int k, m;

vector<pair<int, int>> res;

int f(int x) {
    int res = 0;
    while (x > 0) {
        res += x % 10;
        x /= 10;
    }
    return res;
}

bool check(int x) {
    if (x <= 2) return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

void dfs(int num, int sum, int idx) {
    if (idx == k) {
        if (sum != m) return;
        int n = f(num + 1);
        if (check(gcd(m, n)))
            res.emplace_back(n, num);
        return;
    }
    if (sum > m or sum + (k - idx) * 9 < m) return;
    for (int i = !(idx > 0); i < lim; ++i)
        dfs(num * 10 + i, sum + i, idx + 1);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    for (int __ = 1; __ <= _; ++__) {
        cout << "Case " << __ << '\n';
        cin >> k >> m;
        res.clear();
        dfs(0, 0, 0);
        sort(begin(res), end(res));
        if (res.empty())
            cout << "No Solution" << '\n';
        else
            for (auto &[n, a] : res)
                cout << n << ' ' << a << '\n';
    }
    return 0;
}
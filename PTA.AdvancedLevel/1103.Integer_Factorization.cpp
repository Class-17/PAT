#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, p;
    cin >> n >> k >> p;
    vector<int> facs, temp(k);
    int sum = 0, fac_sum = 0, max_fac_sum = 0;
    auto dfs = [&](auto &dfs, int num, int pos)->void {
        if (pos == k) {
            if (sum != n || fac_sum <= max_fac_sum) return;
            facs = temp;
            max_fac_sum = fac_sum;
            return;
        }
        if (sum + (k - pos) > n || sum + pow(num, p) * (k - pos) < n) return;
        for (int val = num; val > 0; --val) {
            int produc = pow(val, p);
            temp[pos] = val;
            sum += produc; fac_sum += val;
            dfs(dfs, val, pos + 1);
            sum -= produc; fac_sum -= val;
        }
    };
    dfs(dfs, pow(n - k + 1, 1.0 / p), 0);
    if (facs.empty())
        cout << "Impossible" << '\n';
    else {
        cout << n << " = ";
        for (int i = 0; i < k; ++i)
            cout << facs[i] << '^' << p << (i + 1 < k ? " + " : "\n");
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    long double sum = 0.0L;
    for (int i = 1; i <= n; ++i) {
        double x; cin >> x;
        sum += x * i * (n + 1 - i);
    }
    cout << setprecision(2) << fixed<< sum << '\n';
    return 0;
}
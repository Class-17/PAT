#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int x = 0, y = 1;
    for (int i = 0; i < n; ++i) {
        ll a, b;
        char op;
        cin >> a >> op >> b;
        tie(a, b) = pair{a / __gcd(a, b), b / __gcd(a, b)};
        x = x * b + a * y;
        y *= b;
        tie(x, y) = pair{x / __gcd(x, y), y / __gcd(x, y)};
    }
    if (y == 1)
        cout << x << '\n'; 
    else if (x < y)
        cout << x << '/' << y << '\n';
    else
        cout << x / y << ' ' << x % y << '/' << y << '\n';
    return 0;
}
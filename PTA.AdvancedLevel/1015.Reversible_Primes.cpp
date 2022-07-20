#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; ++i)
        if (n % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, d;
    while (cin >> n && n >= 0) {
        cin >> d;
        if (!is_prime(n))
            cout << "No\n";
        else {
            vector<int> cast;
            do {
                cast.push_back(n % d);
                n /= d;
            } while (n > 0);
            for (auto &x : cast)
                n = n * d + x;
            if (is_prime(n)) cout << "Yes\n";
            else             cout << "No\n";
        }
    }
    return 0;
}
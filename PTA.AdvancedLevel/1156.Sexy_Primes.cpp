#include <bits/stdc++.h>
using namespace std;

constexpr int C = 6;

bool isPrime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    if (isPrime(n - C) and isPrime(n + 6))
        cout << "Yes\n" << n - C << '\n';
    else if (isPrime(n) and isPrime(n + C))
        cout << "Yes\n" << n + C << '\n';
    else {
        cout << "No\n";
        while (true) {
            if (isPrime(n) and isPrime(n + C)) break;
            if (isPrime(n) and isPrime(n - C)) break;
            ++n;
        }
        cout << n << '\n';
    }
    return 0;
}
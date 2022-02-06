#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e4;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n;
    cin >> m >> n;
    while (!isPrime(m)) m++;
    bitset<maxn> st;
    while (n--) {
        int x; cin >> x;
        auto insert = [&]() {
            for (int i = 0; i < m; ++i)
                if (!st[(x + i * i) % m])  {
                    cout << (x + i * i) % m;  
                    st[(x + i * i) % m] = true;
                    return;
                }
            cout << "-"; 
        };
        insert();
        cout << (n != 0 ? ' ' : '\n');
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int len = 0, l = 0, r = 0;
    for (int i = 2; 1LL * i * i <= n; ++i) {
        if (n % i) continue;
        int j = i, num = n;
        while (num % j == 0) 
            tie(num, j) = pair{num / j, j + 1};
        if (j - i > len)
            tie(l, r, len) = tuple{i, j, j - i};
    }
    if (len == 0) {
        cout << 1 << '\n' << n << '\n';
    }
    else {
        cout << len << '\n';
        for(int i = l; i < r; ++i)
            cout << i << (i + 1 < r ? '*' : '\n');
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5;

vector<int> primes;

bitset<maxn + 1> st;

void sieve(int n) {
    for (int i = 2; i <= n; ++i) {
        if (st[i]) continue;
        for (int j = i + i; j <= n; j += i)
            st[j] = 1;
        primes.push_back(i);
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    sieve(m);
    int len = size(primes);
    for (int i = m / max(1, (n - 1)); i > 1; --i) {
        for (int j = len - 1; j >= n - 1; --j) {
            int p = primes[j], curr = 0;
            vector<int> seq;
            while (size(seq) < n and p >= 2) {
                if (st[p]) break;
                seq.push_back(p);
                p -= i;
            }
            if (size(seq) < n) continue;
            for (int k = n - 1; k >= 0; --k)
                cout << seq[k] << (k > 0 ? ' ' : '\n');
            return 0;
        }
    }
    cout << primes.back() << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

using ll = long long;

constexpr int maxn = 1e5;

bool is_prime(int n) {
    if (n < 2) return false;
    for (int i = 2; 1LL * i * i <= n; i++)
        if (n % i == 0) return false;
    return true;
}

void sieve(vector<int> &primes) {
    bitset<maxn + 1> st;
    for (int i = 2; i <= maxn; ++i) {
        if (st[i]) continue;
        for (int j = i + i; j <= maxn; j += i)
            st[j] = true;
        primes.push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> primes;
    sieve(primes);
    ll n; cin >> n;
    vector<pair<int, int>> seq;
    if (n == 1) {cout << "1=1\n"; return 0;}
    cout << n << "=";
    for (auto &x : primes) {
        if (n < x) break;
        if (n % x) continue;
        seq.push_back({x, 0});
        while (n % x == 0) {
            seq.back().second++;
            n /= x;
        }
    }
    for (int i = 0; i < size(seq); ++i) {
        cout << seq[i].first;
        if (seq[i].second > 1)
            cout << '^' << seq[i].second;
        cout << (i + 1 < size(seq) ? '*' : '\n');
    }
    return 0;
}
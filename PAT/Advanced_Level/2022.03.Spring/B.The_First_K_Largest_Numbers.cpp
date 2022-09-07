#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    priority_queue<ll> pq;
    k = min(n, k);
    for (int i = 0; i < n; ++i) {
        ll x; cin >> x;
        pq.push(-x);
        if (size(pq) > k) pq.pop();
    }
    if (size(pq) > k) pq.pop();
    vector<ll> res;
    while (!pq.empty()) {
        res.push_back(-pq.top());
        pq.pop();
    }
    reverse(begin(res), end(res));
    for (int i = 0; i < k; ++i)
        cout << res[i] << (i + 1 < k ? ' ' : '\n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    priority_queue<int, vector<int>, greater<>> pq(begin(arr), end(arr));
    while (pq.size() > 1) {
        auto a = pq.top(); pq.pop();
        auto b = pq.top(); pq.pop();
        pq.push((a + b) / 2);
    }
    cout << pq.top() << '\n';
    return 0;
}
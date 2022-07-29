#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5;

pair<int, int> llist[maxn];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, head;
    cin >> n >> head;
    for (int i = 0; i < n; ++i) {
        int ptr, val, nptr;
        cin >> ptr >> val >> nptr;
        llist[ptr] = {val, nptr}; 
    }
    vector<pair<int, int>> arr;
    while (head != -1) {
        arr.emplace_back(llist[head].first, head);
        head = llist[head].second;
    }
    sort(begin(arr), end(arr));
    cout << size(arr) << ' ';
    for (auto &[val, ptr] : arr) {
        cout << setw(5) << setfill('0') << ptr << '\n';
        cout << setw(5) << setfill('0') << ptr << ' ';
        cout << val << ' ';
    }
    cout << -1 << '\n';
    return 0;
}
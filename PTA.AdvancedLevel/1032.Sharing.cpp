#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h1, h2, n;
    (cin >> h1 >> h2 >> n).get();
    int nodes[MAXN];
    for (int i = 0; i < n; ++i) {
        string node; 
        getline(cin, node);
        nodes[stoi(node.substr(0, 5))] = stoi(node.substr(8));
    }
    unordered_set<int> memo;
    int rear = h1;
    while (rear != -1) {
        memo.insert(rear);
        rear = nodes[rear];
    }
    auto traversal = [&]() {
        int rear = h2;
        while (rear != -1) {
            if (memo.find(rear) != memo.end()) return rear;
            rear = nodes[rear];
        }
        return -1;
    };
    int res = traversal();
    if (res == -1)
        cout << -1 << endl;
    else
        cout << setfill('0') << setw(5) << res << endl;
    return 0;
}

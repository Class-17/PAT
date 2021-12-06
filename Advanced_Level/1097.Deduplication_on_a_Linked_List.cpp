#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5;

struct node {
    int val, next;
} nodes[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int head, n;
    cin >> head >> n;
    for (int i = 0; i < n; ++i) {
        int p; cin >> p;
        cin >> nodes[p].val >> nodes[p].next;
    }
    nodes[MAXN].next = head;
    vector<pair<int, int>> seq;
    bool memo[10001] = {false};
    int rear = MAXN;
    while (rear != -1 &&  nodes[rear].next != -1 ) {
        while (nodes[rear].next != -1) {
            int p = nodes[rear].next;
            if (!memo[abs(nodes[p].val)]) break;
            seq.push_back({p, nodes[p].val});
            nodes[rear].next = nodes[nodes[rear].next].next;
        }
        memo[abs(nodes[nodes[rear].next].val)] = true;
        rear = nodes[rear].next;
    }
    rear = nodes[MAXN].next;
    while (rear != -1) {
        cout << setfill('0') << setw(5) << rear;
        cout << ' ' << nodes[rear].val << ' ';
        if (nodes[rear].next == -1)
            cout << -1 << endl;
        else
            cout << setfill('0') << setw(5) << nodes[rear].next << endl;
        rear = nodes[rear].next;
    }
    for (int i = 0; i < size(seq); ++i) {
        cout << setfill('0') << setw(5) << seq[i].first;
        cout << ' ' << seq[i].second << ' ';
        if (i + 1 < size(seq))
            cout << setfill('0') << setw(5) << seq[i + 1].first << endl;
        else
            cout << -1 << endl;
    }
    return 0;
}

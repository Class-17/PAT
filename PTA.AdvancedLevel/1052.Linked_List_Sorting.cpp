#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5;

struct node {
    int val, next;
} nodes[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, head; cin >> n >> head;
    for (int i = 0; i < n; ++i) {
        int address;
        cin >> address;
        cin >> nodes[address].val;
        cin >> nodes[address].next;
    }
    int rear = head;
    vector<pair<int, int>> seq;
    while (rear != -1) {
        seq.push_back({nodes[rear].val, rear});
        rear = nodes[rear].next;
    }
    sort(begin(seq), end(seq));
    cout << size(seq) << ' ';
    for (int i = 0; i < size(seq); ++i)
        cout << setfill('0') << setw(5) << seq[i].second << endl
             << setfill('0') << setw(5) << seq[i].second
             << ' ' << seq[i].first << ' ';
    cout << -1 << endl;
    return 0;
}

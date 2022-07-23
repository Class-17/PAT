#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5;

pair<int, int> llist[maxn];

int attach(int &head, int rear, int ptr, bool isList = false) {
    if (head == -1) head = rear = ptr;
    else            llist[rear].second = ptr;
    if (!isList) llist[ptr].second = -1;
    return ptr;
}

void print(int head) {
    while (head != -1) {
        cout << setw(5) << setfill('0') << head << ' ';
        cout << llist[head].first << ' ';
        head = llist[head].second;
        if (head == -1) cout << -1 << '\n';
        else
            cout << setw(5) << setfill('0') << head << '\n';
    }
}

int split(int head, int k) {
    int ha = -1, hb = -1, hc = -1;
    int a = -1, b = -1, c = -1;
    int rear = head;
    while (rear != -1) {
        int val = llist[rear].first;
        int nPtr = llist[rear].second;
        if (val < 0)       a = attach(ha, a, rear);
        else if (val <= k) b = attach(hb, b, rear);
        else               c = attach(hc, c, rear);
        
        rear = nPtr;
    }
    attach(hb, b, hc, true);
    attach(ha, a, hb, true);
    return ha;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < maxn; ++i)
        llist[i] = {0, -1};
    for (int i = 0; i < n; ++i) {
        int ptr, val, nPtr;
        cin >> ptr >> val >> nPtr;
        llist[ptr] = {val, nPtr};
    }
    head = split(head, k);
    print(head);
    return 0;
}
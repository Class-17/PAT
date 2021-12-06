#include <bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e5;

struct node {
    int val, next;
} List[MAXN + 1];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int h, n, k;
    cin >> h >> n >> k;
    for (int i = 0; i < n; ++i) {
        int pos, val, next;
        cin >> pos >> val >> next;
        List[pos].val = val;
        List[pos].next = next;
    }
    int cnt = 0;
    for (int rear = h; rear != -1; rear = List[rear].next) cnt++;
    n = cnt;
    List[MAXN].next = h;
    int curr = MAXN;
    for (int round = 0; round < n / k; ++round) {
        int new_head = curr, old_head = List[curr].next;
        for (int i = 0; i < k; ++i) {
            int temp = List[old_head].next;
            List[old_head].next = new_head;
            new_head = old_head;
            old_head = temp;
        }
        int temp = List[curr].next;
        List[curr].next = new_head;
        List[temp].next = old_head;
        curr = temp;
    }
    int rear = List[MAXN].next;
    while (rear != -1) {
        cout << setw(5) << setfill('0') << rear << " ";
        cout << List[rear].val << " ";
        if (List[rear].next != -1)
            cout << setw(5) << setfill('0') << List[rear].next << endl;
        else
            cout << -1 << endl;
        rear = List[rear].next;
    }
    return 0;
}
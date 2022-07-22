#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5;

int vals[maxn], ptrs[maxn];

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h, n, k;
    cin >> h >> n >> k;
    for (int i = 0; i < n; ++i) {
        int p, val, ptr;
        cin >> p >> val >> ptr;
        vals[p] = val;
        ptrs[p] = ptr;
    }
    int newHead = -1, oldHead = h;
    while (oldHead != -1) {
        int len = 1;
        int a = oldHead, b = a;
        while (len < k and ptrs[b] != -1) {
            b = ptrs[b];
            ++len;
        }
        int temp = ptrs[b];
        ptrs[b] = newHead;
        newHead = a;
        oldHead = temp;
    }
    int rear = newHead;
    while (rear != -1) {
        cout << setw(5) << setfill('0') << rear << ' ';
        cout << vals[rear] << ' ';
        if (ptrs[rear] == -1)
            cout << ptrs[rear] << '\n';
        else            
            cout << setw(5) << setfill('0') << ptrs[rear] << '\n';
        rear = ptrs[rear];
    }
    return 0;
}
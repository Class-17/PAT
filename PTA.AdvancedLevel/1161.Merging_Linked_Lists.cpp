#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e5;

class List {
private:
    int val[maxn];
    int ptr[maxn];
    int h, len;
public:
    List(int h) : h(h), len(0) {memset(ptr, -1, sizeof ptr);}
    
    int head() {return h;}
    
    int size() {return len;}
    
    pair<int, int> node(int p) {return {val[p], ptr[p]};}
    
    void pop() {
        int temp = ptr[h];
        ptr[h] = -1;
        h = temp;
        --len;
    }
    
    void insert(int p, int x, int np) {
        val[p] = x;
        ptr[p] = np;
        ++len;
    }
    
    void reverse() {
        int p1 = -1, p2 = h;
        while (p2 != -1) {
            int temp = ptr[p2];
            ptr[p2] = p1;
            p1 = p2;
            p2 = temp;
        }
        h = p1;
    }
    
    void merge(List &x) {
        int rear = h;
        for (int i = 0; rear != -1 and x.size() > 0; ++i) {
            if (i & 1) {
                int temp = ptr[rear], p = x.head();
                auto [value, np] = x.node(p); x.pop();
                ptr[rear] = p;
                insert(p, value, temp);
                rear = p;
            }
            rear = ptr[rear];
        }
    }
    
    void print() {
        int rear = h;
        while (rear != -1) {
            cout << setfill('0') << setw(5) << rear << ' ';
            cout << val[rear] << ' ';
            if (ptr[rear] == -1) cout << -1 << '\n';
            else
                cout << setfill('0') << setw(5) << ptr[rear] << '\n';
            rear = ptr[rear];
        }
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int h1, h2, n;
    cin >> h1 >> h2 >> n;
    List l1(h1), l2(h2);
    map<int, pair<int, int>> nodes;
    for (int i = 0; i < n; ++i) {
        int p, val, np;
        cin >> p >> val >> np;
        nodes[p] = {val, np};
    }
    auto build = [&](List &l)->void {
        int p = l.head();
        while (p != -1) {
            auto [val, np] = nodes[p];
            l.insert(p, val, np);
            p = np;
        }
    };
    build(l1);
    build(l2);
    if (l1.size() < l2.size()) swap(l1, l2);
    l2.reverse();
    l1.merge(l2);
    l1.print();
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class people {
public:
    string id;
    int a, b, rank;

    people(string id, int a, int b, int rank) : 
        id(id), a(a), b(b), rank(rank) {}

    bool operator < (const people& x) const {
        if (rank == x.rank) {
            if (a + b == x.a + x.b) {
                if (a == x.a) return id < x.id;
                return a > x.a;
            }
            return a + b > x.a + x.b;
        }
        return rank < x.rank;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, l, h;
    cin >> n >> l >> h;
    vector<people> arr;
    for (int i = 0; i < n; ++i) {
        string id;
        int a, b, rank;
        cin >> id >> a >> b;
        if (a < l or b < l) continue;
        if (a >= h and b >= h) rank = 1;
        else if (a >= h)       rank = 2;
        else if (a >= b)       rank = 3;
        else                   rank = 4;
        arr.emplace_back(id, a, b, rank);
    }
    sort(begin(arr), end(arr));
    cout << size(arr) << '\n';
    for (auto &[id, a, b, rank] : arr)
        cout << id << ' ' << a << ' ' << b << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 1e3;

constexpr int inf = 0x3f3f3f3f;

int arr[maxn];

int len;

void insert(const int &x) {
    arr[len] = x;
    int p = len++;
    while (p > 0) {
        int fa = (p - 1) / 2;
        if (arr[p] > arr[fa])
            swap(arr[p], arr[fa]);
        p = fa;
    }  
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int x; cin >> x;
        insert(x);
    }
    map<int, int> mp;
    auto get = [&](const int x) {
        if (mp.find(x) == mp.end()) return inf;
        return mp[x];
    };
    for (int i = 0; i < n; ++i)
        mp[arr[i]] = i;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        x = get(x);
        string s;
        cin >> s;
        if (s == "is") {
            for (int j = 0; j < 2; ++j)
                cin >> s;
            if (s == "root") {
                cout << (x == 0);
            }
            else if (s == "left") {
                for (int j = 0; j < 2; ++j)
                    cin >> s;
                int y; cin >> y;
                y = get(y);
                if (x == inf or y == inf)
                    cout << 0;
                else
                    cout << (y * 2 + 1 == x);
            }
            else if (s == "right") {
                for (int j = 0; j < 2; ++j)
                    cin >> s;
                int y; cin >> y;
                y =get(y);
                if (x == inf or y == inf)
                    cout << 0;
                else
                    cout << (y * 2 + 2 == x);
            }
            else {
                cin >> s;
                int y; cin >> y;
                y = get(y);
                if (x == inf or y == inf)
                    cout << 0;
                else
                    cout << ((y - 1) / 2 == x);
            }
        }
        else {
            int y; cin >> y;
            y = get(y);
            for (int j = 0; j < 2; ++j)
                cin >> s;
            if (x == inf or y == inf)
                cout << 0;
            else
                cout << ((x - 1) / 2 == (y - 1) / 2);
        }
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

struct info {
    string id;
    int vg, tg, level;
    bool operator < (const info &x) const {
        if (level != x.level)    return level < x.level;
        if (vg + tg != x.vg + x.tg)
            return vg + tg > x.vg + x.tg;
        if (vg != x.vg)   
            return vg > x.vg;
        return id < x.id;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, l, h;
    cin >> n >> l >> h;
    vector<info> elems;
    for (int i = 0; i < n; ++i) {
        info elem;
        cin >> elem.id >> elem.vg >> elem.tg;
        if (min(elem.vg, elem.tg) < l) continue;
        if (min(elem.vg, elem.tg) >= h)
                elem.level = 1;
        else if (elem.vg >= h)
                elem.level = 2;
        else if (elem.vg >= elem.tg)
                elem.level = 3;
        else    elem.level = 4;
        elems.push_back(elem);
    }
    cout << size(elems) << '\n';
    sort(begin(elems), end(elems));
    for (auto &elem : elems)
        cout << elem.id << ' ' << elem.vg << ' ' << elem.tg << '\n';
    return 0;
}
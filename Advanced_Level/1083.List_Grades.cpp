#include <bits/stdc++.h>
using namespace std;

struct info {
    string name, id;
    int grade;
    bool operator < (const info &x) const {
        return grade < x.grade; 
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<info> seq(n);
    for (auto &x: seq)
        cin >> x.name >> x.id >> x.grade;
    sort(rbegin(seq), rend(seq));
    int a, b;
    cin >> a >> b;
    int lo = n, hi = -1;
    for (int i = 0; i < n; ++i) {
        if (seq[i].grade <= b)
            lo = min(i, lo);
        if (seq[i].grade >= a)
            hi = max(i, hi);
    }
    if (lo > hi)
        cout << "NONE" << '\n';
    else {
        while (lo <= hi) {
            cout << seq[lo].name << ' ' << seq[lo].id << '\n';
            lo++;
        }
    }
    return 0;
}
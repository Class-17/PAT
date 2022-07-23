#include <bits/stdc++.h>
using namespace std;

class student {
public:
    string id;
    int gp, gm, gf, g;

    student() {}

    student(string id) : id(id) {
        gp = gm = gf = g = -1;
    }

    bool operator < (const student &x) const {
        if (g == x.g) return id < x.id;
        return g > x.g;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int p, m, n;
    cin >> p >> m >> n;
    map<string, student> mp;
    for (int i = 0; i < p; ++i) {
        string id; cin >> id;
        int x; cin >> x;
        if (mp.find(id) == mp.end());
            mp.emplace(id, student(id));
        mp[id].gp = x;
    }
    for (int i = 0; i < m; ++i) {
        string id; cin >> id;
        int x; cin >> x;
        if (mp.find(id) == mp.end());
            mp.emplace(id, student(id));
        mp[id].gm = x;
    }
    for (int i = 0; i < n; ++i) {
        string id; cin >> id;
        int x; cin >> x;
        if (mp.find(id) == mp.end());
            mp.emplace(id, student(id));
        mp[id].gf = x;
    }
    vector<student> res;
    for (auto &[_, stu] : mp) {
        auto &[id, gp, gm, gf, g] = stu;
        if (gm == -1 and gf == -1) g = -1;
        else if (gf > gm)
            g = gf;
        else if (gm != -1 and gf != -1)
            g = round(gm * 0.4 + gf * 0.6);
        if (gp >= 200 and g >= 60)
            res.push_back(stu);
    }
    sort(begin(res), end(res));
    for (auto &[id, gp, gm, gf, g] : res)
        cout << id << ' ' << gp << ' ' << gm << ' ' << gf << ' ' << g << '\n';
    return 0;
}
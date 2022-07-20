#include <bits/stdc++.h>
using namespace std;

constexpr int MAXAGE = 200;
constexpr int MAXM = 100;

struct info {
    string id;
    int age, worth;
};

bool check(const info &a, const info &b, int lo, int hi) {
    if (a.age <  lo || a.age > hi) return false;
    if (b.age < lo || b.age > hi) return true;
    if (a.worth == b.worth)
        if (a.age == b.age) return a.id < b.id;
        else return a.age < b.age;
    return a.worth > b.worth;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<vector<info>> src(MAXAGE + 1);
    for (int i = 0; i < n; ++i) {
        info x;
        cin >> x.id >> x.age >> x.worth;
        src[x.age].push_back(x);
    }
    vector<info> data;
    for (int i = 0; i <= MAXAGE; ++i) {
        sort(src[i].begin(), src[i].end(), [&](const auto &a, const auto &b) {
            return check(a, b, i, i);
        });
        for (int j = 0; j < MAXM && j < size(src[i]); ++j)
            data.push_back(src[i][j]);
    }
    sort(data.begin(), data.end(), [&](const auto &a, const auto& b) {
        return check(a, b, 0, MAXAGE);
    });
    for (int i = 1; i <= k; ++i) {
        int m, lo, hi;
        cin >> m >> lo >> hi;
        cout << "Case #" << i << ":\n";
        int num = 0;
        for (int i = 0; i < size(data) && num < m; ++i) {
            if (data[i].age < lo || data[i].age > hi) continue;
            cout << data[i].id << ' ' << data[i].age << ' ' << data[i].worth << '\n';
            num++;
        }
        if (num == 0) cout << "None\n";
    }
    return 0;
}
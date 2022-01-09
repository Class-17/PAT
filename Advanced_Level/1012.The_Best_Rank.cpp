#include <bits/stdc++.h>
using namespace std;

struct info {
    int id;
    pair<int, int> gr[4];
};

constexpr char courses[4] = {'A', 'C', 'M', 'E'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<info> elems(n);
    for (auto &elem : elems) {
        cin >> elem.id;
        for (int i = 1; i < 4; ++i)
            cin >> elem.gr[i].first;
        elem.gr[0].first = (elem.gr[1].first + elem.gr[2].first + elem.gr[3].first) / 3;
    }
    for (int tag = 0; tag < 4; ++tag) {
        sort(begin(elems), end(elems), [&](const auto &a, const auto &b) {
            if (a.gr[tag].first == b.gr[tag].first)
                return a.id < b.id;
            return a.gr[tag].first > b.gr[tag].first;
        });
        elems[0].gr[tag].second = 1;
        for (int i = 1; i < n; ++i)
            elems[i].gr[tag].second = (elems[i].gr[tag].first == elems[i - 1].gr[tag].first ?
                elems[i - 1].gr[tag].second : i + 1);
    }
    unordered_map<int, int> mp;
    for (int i = 0; i < size(elems); ++i)
        mp[elems[i].id] = i;
    while (m--) {
        int x; cin >> x;
        if (mp.find(x) == mp.end())
            cout << "N/A\n";
        else {
            info &elem = elems[mp[x]];
            int c = min_element(elem.gr, elem.gr + 4, [](const auto &a, const auto &b) {
                return a.second < b.second;}) - elem.gr;
            cout << elem.gr[c].second << ' ' << courses[c] << '\n';
        }
    }
    return 0;
}
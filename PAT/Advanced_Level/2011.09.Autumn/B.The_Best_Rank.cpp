#include <bits/stdc++.h>
using namespace std;

constexpr char f[] {'A', 'C', 'M', 'E'};

struct info {
    vector<int> val;
    char ch;
    int rank;
    
    info() {}
    info(int c, int m, int e) {
        val.push_back(c + m + e);
        val.push_back(c);
        val.push_back(m);
        val.push_back(e);
        rank = INT_MAX;
    } 
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    map<string, info> stus;
    vector<string> idx;
    for (int i = 0; i < n; ++i) {
        string id;
        int c, m, e;
        cin >> id >> c >> m >> e;
        stus[id] = info(c, m, e);
        idx.push_back(id);
    }
    auto get_rank = [&](int g)->void {
        sort(begin(idx), end(idx), [&](const auto &a, const auto &b) {
            if (stus[a].val[g] == stus[b].val[g]) return a < b;
            return stus[a].val[g] > stus[b].val[g];
        });
        for (int i = 0, r = 1; i < n; ++i) {
            string &id = idx[i];
            if (i > 0 and stus[id].val[g] != stus[idx[i - 1]].val[g]) r = i + 1;
            if (r < stus[id].rank) {
                stus[id].rank = r;
                stus[id].ch = f[g];
            }
        }
    };
    for (int i = 0; i < 4; ++i)
        get_rank(i);
    for (int i = 0; i < m; ++i) {
        string id; cin >> id;
        if (stus.find(id) == stus.end())
            cout << "N/A" << '\n';
        else {   
            cout << stus[id].rank << ' ' << stus[id].ch << '\n';
        }
    }
    return 0;
}
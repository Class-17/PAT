#include <bits/stdc++.h>
using namespace std;

struct info {
    string id;
    int score, loc_num, loc_rank;
    bool operator < (const info &x) const {
        if (score == x.score) return id < x.id;
        return score > x.score;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<info> elems;
    for (int i = 0; i < n; i++) {
        int k; cin >> k;
        for (int j = 0; j < k; j++) {
            info elem;
            cin >> elem.id >> elem.score;
            elem.loc_num = i + 1;
            elems.push_back(elem);
        }
        int p = int(size(elems)) - k;
        sort(begin(elems) + p, end(elems));
        elems[p].loc_rank = 1;
        for (int j = p + 1; j < size(elems); ++j)
            elems[j].loc_rank = elems[j].score == elems[j - 1].score ? 
                elems[j - 1].loc_rank : j - p + 1;
    }
    sort(begin(elems), end(elems));
    cout << size(elems) << '\n';
    for (int i = 0, rank = 1; i < size(elems); i++) {
        if (i != 0 && elems[i].score < elems[i - 1].score) rank = i + 1;
        cout << elems[i].id << ' ' << rank << ' ' << elems[i].loc_num << ' ' << elems[i].loc_rank << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

constexpr int none = -10;

struct info {
    vector<int> gr;
    int id, score, ac_num;
    bool operator < (const info &x) const {
        if (score == x.score)
            if (ac_num == x.ac_num) return id < x.id;
            else                        return ac_num > x.ac_num;
        return score > x.score;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, m;
    cin >> n >> k >> m;
    vector<int> p(k);
    for (auto &x : p) cin >> x;
    vector<info> stus(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < k; ++j)
            stus[i].gr.push_back(none);
        stus[i].id = i + 1;
        stus[i].score = 0;
        stus[i].ac_num = 0;
    }
    for (int i = 0; i < m; i++) {
        int id, p_num, score;
        cin >> id >> p_num >> score;
        if (score == -1) score = 0;
        if (score <= stus[id - 1].gr[p_num - 1]) continue;
        if (stus[id - 1].gr[p_num - 1] != none)
            stus[id - 1].score += score - stus[id - 1].gr[p_num - 1];
        else   
            stus[id - 1].score += score;
        stus[id - 1].gr[p_num - 1] = score;
        if (score == p[p_num - 1]) stus[id - 1].ac_num++;
    }
    sort(begin(stus), end(stus));
    for (int i = 0, rank = 1; i < n; ++i) {
        if (all_of(begin(stus[i].gr), end(stus[i].gr), [](const auto &x) {
            return x == none;})) break;
        if (i > 0 && stus[i - 1].score > stus[i].score) rank = i + 1;
        cout << rank << ' ' << setw(5) << setfill('0') << stus[i].id << ' ' << stus[i].score;
        for (auto &q : stus[i].gr)
            cout << ' ' << (q != none ? to_string(q) : "-");
        cout << '\n';
    }  
    return 0;
}
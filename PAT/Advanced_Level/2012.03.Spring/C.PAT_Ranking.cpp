#include <bits/stdc++.h>
using namespace std;

class student {
public:
    string id;
    int score, num, rank;

    bool operator < (const student &x) const {
        if (score == x.score) return id < x.id;
        return score > x.score;
    }
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<student> stus;
    for (int i = 0; i < n; ++i) {
        int k; cin >> k;
        vector<student> curr(k);
        for (auto &[id, score, num, rank] : curr)
            cin >> id >> score;
        sort(begin(curr), end(curr));
        curr[0].rank = 1;
        for (int j = 1; j < k; ++j) {
            if (curr[j].score == curr[j - 1].score)
                curr[j].rank = curr[j - 1].rank;
            else
                curr[j].rank = j + 1;
        }
        for (auto &x : curr) {
            x.num = i + 1;
            stus.push_back(x);
        }
    }
    sort(begin(stus), end(stus));
    cout << size(stus) << '\n';
    for (int i = 0, j = 0; i < size(stus); ++i) {
        if (i > 0 and stus[i].score < stus[i - 1].score)
            j = i;
        cout << stus[i].id << ' ' << j + 1 << ' ' << stus[i].num << ' ' << stus[i].rank << '\n';
    }
    return 0;
}
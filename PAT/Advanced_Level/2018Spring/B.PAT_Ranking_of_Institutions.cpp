#include <bits/stdc++.h>
using namespace std;

struct info {
    string name;
    int score, num;
    info(const string &name, int score, int num) :
        name(name), score(score), num(num) {}
    bool operator < (const info &b) const {
        if (b.score == score)
            if (b.num == num) return name < b.name;
            else              return num < b.num;
        return score > b.score;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<string, pair<double, int>> sh;
    for (int i = 0; i < n; ++i) {
        string id, school;
        double score;
        cin >> id >> score >> school;
        if (id[0] == 'T') score *= 1.5;
        else if (id[0] == 'B') score /= 1.5;
        for (auto &x : school) x = tolower(x);
        sh[school].first += score;
        sh[school].second++;
    }
    vector<info> seq;
    for (auto &[name, x] : sh) {
        seq.push_back(info(name, int(x.first), x.second));
    }
    sort(begin(seq), end(seq));
    cout << size(seq) << endl;
    int rank = 1;
    for (int i = 0; i < size(seq); ++i) {
        cout << rank << ' ' << seq[i].name << ' ' 
             << seq[i].score << ' ' << seq[i].num << endl;
        if (i + 1 < size(seq) && seq[i].score > seq[i + 1].score)
            rank = i + 2;
    }
    return 0;
}
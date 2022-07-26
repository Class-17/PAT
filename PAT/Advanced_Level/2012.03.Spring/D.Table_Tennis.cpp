#include <bits/stdc++.h>
using namespace std;

constexpr int S = 8 * 60 * 60;
constexpr int E = 21 * 60 * 60;

class pairs {
public:
    int tA, tS, w, waitTime;
    pairs(int tA, int tS, int w, int waitTime) :
        tA(tA), tS(tS), w(w), waitTime(waitTime) {}
};

class table {
public:
    int id, time, vip;
    table(int id, int time, int vip) : 
        id(id), time(time), vip(vip) {}
};

string f(int x) {
    auto h = to_string(x / 60 / 60);
    auto m = to_string(x / 60 % 60);
    auto s = to_string(x % 60);
    auto up = [](string &s) {
        while (size(s) < 2) s.insert(begin(s), '0');
    };
    up(h), up(m), up(s);
    return h + ":" + m + ":" + s;
}

vector<pairs> seqA, seqB;

vector<int> solve(int k, set<int> &vips) {
    vector<int> cnt(k);
    vector<table> ts;
    for (int i = 0; i < k; ++i)
        ts.emplace_back(i, S, vips.find(i) != vips.end());
    auto find_table = [&](int curr_time, int lim) {
        for (int i = 0; i < k; ++i)
            if ((!ts[i].vip or ts[i].time < lim)
                and ts[i].time <= curr_time) return i;
        int res = -1; 
        for (int i = 0; i < k; ++i)
            if ((!ts[i].vip or ts[i].time < lim)
                and (res == -1 or ts[i].time < ts[res].time)) res = i;
        return res;
    };
    auto find_vip_table = [&](int curr_time) {
        for (int i = 0; i < k; ++i)
            if (ts[i].vip and ts[i].time <= curr_time) return i;
        int res = -1;
        for (int i = 0; i < k; ++i)
            if (ts[i].vip and (res == -1 or ts[i].time < ts[res].time)) res = i;
        return res;
    };
    auto process = [&](pairs &x, int idx) {
        auto &[tA, tS, w, waitTime] = x;
        auto &[id, time, vip] = ts[idx];
        tS = max(tA, time);
        int gap = tS - tA;
        waitTime = (gap + 30) / 60;
        time = tS + w;
        if (tS < E) ++cnt[idx];
    };
    int n = size(seqA), m = size(seqB), i = 0, j = 0;
    while (i < n and j < m) {
        int idxA = find_table(seqA[i].tA, E);
        int idxB = find_table(seqB[j].tA, seqA[i].tA);
        auto check = [&] () {
            int idxVip = find_vip_table(seqA[i].tA);
            if (ts[idxVip].time <= ts[idxA].time or ts[idxVip].time <= seqA[i].tA)
                idxA = idxVip;
            if (seqA[i].tA < seqB[j].tA) return true;
            
            if (ts[idxVip].time > ts[idxB].time) return false;
            if (ts[idxVip].time < seqA[i].tA) return false;
            idxA = idxVip;
            return true;
        };
        if (check()) process(seqA[i++], idxA);
        else         process(seqB[j++], idxB);
    }
    while (i < n) {
        int idxA = find_table(seqA[i].tA, E);
        int idxVip = find_vip_table(seqA[i].tA);
        if (ts[idxVip].time <= ts[idxA].time or ts[idxVip].time <= seqA[i].tA)
            idxA = idxVip;
        process(seqA[i], idxA);
        ++i;
    }
    while (j < m) {
        process(seqB[j], find_table(seqB[j].tA, E));
        ++j;
    }
    return cnt;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        string t;
        int w, vip;
        cin >> t >> w >> vip;
        w = min(w * 60, 2 * 60 * 60);
        int tA = stoi(t.substr(0, 2)) * 60 * 60 + stoi(t.substr(3, 2)) * 60 + stoi(t.substr(6, 2));
        if (vip) seqA.emplace_back(tA, E, w, 0);
        else     seqB.emplace_back(tA, E, w, 0);
    }
    sort(begin(seqA), end(seqA), [&](const auto &a, const auto &b) {
        return a.tA < b.tA;});
    sort(begin(seqB), end(seqB), [&](const auto &a, const auto &b) {
        return a.tA < b.tA;});
    int k, m;
    cin >> k >> m;
    set<int> vips;
    for (int i = 0; i < m; ++i) {
        int x; cin >> x;
        vips.insert(x - 1);
    }
    auto res = solve(k, vips);
    for (auto &x : seqB) seqA.push_back(x);
    sort(begin(seqA), end(seqA), [&](const auto &a, const auto &b) {
        return a.tS < b.tS;});
    for (auto &[tA, tS, w, waitTime] : seqA) {
        if (tS >= E) break;
        cout << f(tA) << ' ' << f(tS) << ' ' << waitTime << '\n';
    }
    for (int i = 0; i < k; ++i)
        cout << res[i] << (i + 1 < k ? ' ' : '\n');
    return 0;
}
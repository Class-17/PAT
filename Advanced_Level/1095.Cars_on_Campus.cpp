#include <bits/stdc++.h>
using namespace std;

constexpr int max_time = 60 * 60 * 24;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<string>> records(n, vector<string>(3));
    for (auto &line : records)
        for (auto &x : line) cin >> x;
    auto convert = [](const string &t) {
        return stoi(t.substr(0, 2)) * 3600 + stoi(t.substr(3, 2)) * 60 + stoi(t.substr(6, 2));
    };
    sort(begin(records), end(records), [&](const auto &a, const auto &b) {
        if (a[0] == b[0]) return convert(a[1]) < convert(b[1]);
        return a[0] < b[0];});
    int len = 0;
    map<string, int> cars;
    int max_period = 0;
    for (int i = 1; i < n; ++i)
        if (records[i][2] == "out" && records[i - 1][2] == "in" && records[i][0] == records[i - 1][0]) {
            cars[records[i][0]] += convert(records[i][1]) - convert(records[i - 1][1]);
            max_period = max(max_period, cars[records[i][0]]);
            records[len++] = records[i - 1];
            records[len++] = records[i];
        }
    records.resize(len);
    sort(begin(records), end(records), [&](const auto &a, const auto &b) {
        return convert(a[1]) < convert(b[1]);});
    unordered_set<string> park;
    for (int i = 0, p = 0; i < m; ++i) {
        string qt; cin >> qt;
        int t = convert(qt);
        while (p < len) {
            int curr_t = convert(records[p][1]);
            auto &car = records[p][0];
            if (curr_t > t) break;
            if (records[p][2] == "in")
                park.insert(car);
            else if (park.find(car) != park.end())
                park.erase(car);
            p++;
        }
        cout << size(park) << '\n';
    }
    for (auto &[car, t] : cars)
        if (t == max_period) cout << car << ' ';
    auto output = [&](const auto &x, const auto &ch) {
        cout << setw(2) << setfill('0') << x << ch;
    };
    output(max_period / 3600, ':');
    output(max_period / 60 % 60, ':');
    output(max_period % 60, '\n');
    return 0;
}
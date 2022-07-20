#include <bits/stdc++.h>
using namespace std;

vector<pair<string, int>> levels[3];
map<int, pair<int, int>> sites;
map<int, map<int, int>> dates;
map<int, vector<pair<int, int>>> order_dates;

int f(const char &ch) {
    return ch == 'T' ? 0 : ch == 'A' ? 1 : 2;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        string s;
        int val;
        cin >> s >> val;
        levels[f(s[0])].emplace_back(s, val);
        int site = stoi(s.substr(1, 3));
        int date = stoi(s.substr(4, 6));
        int testee = stoi(s.substr(10, 3));
        sites[site].first += 1;
        sites[site].second += val;
        dates[date][site] += 1;
    }
    for (int i = 0; i < 3; ++i) {
        sort(begin(levels[i]), end(levels[i]), [](const auto &a, const auto &b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
    }
    for (auto &[date, all_sites] : dates) {
        for (auto &[site, cnt] : all_sites)
            order_dates[date].emplace_back(site, cnt);
        sort(begin(order_dates[date]), end(order_dates[date]), [](const auto &a, const auto &b) {
            if (a.second == b.second) return a.first < b.first;
            return a.second > b.second;
        });
    }    
    for (int i = 1; i <= m; ++i) {
        int type;
        cin >> type;
        cout << "Case " << i << ": " << type << ' ';
        if (type == 1) {
            char level; cin >> level;
            cout << level << '\n';
            if (levels[f(level)].empty())
                cout << "NA" << '\n';
            else
                for (auto &[s, val] : levels[f(level)])
                    cout << s << ' ' << val << '\n';
        }
        else if (type == 2) {
            int site; cin >> site;
            cout << site << '\n';
            if (sites.find(site) == sites.end())
                cout << "NA" << '\n';
            else
                cout << sites[site].first << ' ' << sites[site].second << '\n';
        }
        else if (type == 3) {
            string date; cin >> date;
            cout << date << '\n';
            if (order_dates.find(stoi(date)) == order_dates.end())
                cout << "NA" << '\n';
            else
                for (auto &[site, cnt] : order_dates[stoi(date)])
                    cout << site << ' ' << cnt << '\n';
        }
    }
    return 0;
}
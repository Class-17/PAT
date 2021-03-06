#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; (cin >> n).get();
    vector<unordered_map<string, set<string>>> info(5);
    while (n--) {
        vector<string> book(6);
        for (int i = 0; i < 6; ++i) {
            getline(cin, book[i]);
            if (i != 0 && i != 3) 
                info[i - 1][book[i]].insert(book[0]);
        }
        for (int i = 0; i < size(book[3]); ++i) {
            int p = i;
            while (p < size(book[3]) && book[3][p] != ' ') p++;
            info[2][book[3].substr(i, p - i)].insert(book[0]);
            i = p;
        }
    }
    int m; (cin >> m).get();
    while (m--) {
        string query;
        getline(cin, query);
        cout << query << '\n';
        int q = query[0] - '0';
        query.erase(0, 3);
        if (!info[q - 1][query].empty())
            for (auto &term : info[q - 1][query])
                cout << term << '\n';
        else cout << "Not Found" << '\n';
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

bool comp(const string &a, const string &b) {
    if (a == "") return true;
    return b.substr(7, 8) < a.substr(7, 8);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    set<string> st;
    for (int i = 0; i < n; ++i) {
        string s; cin >> s;
        st.insert(s);
    }
    int m; cin >> m;
    string res, err;
    int cnt = 0;
    for (int i = 0; i < m; ++i) {
        string s; cin >> s;
        if (comp(err, s)) err = s;
        if (st.find(s) == st.end()) continue;
        if (comp(res, s)) res = s;
        ++cnt;
    }
    cout << cnt << '\n';
    cout << (cnt ? res : err) << '\n';
    return 0;
}
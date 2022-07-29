#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int m, n, s;
    cin >> m >> n >> s;
    vector<string> strs(m);
    for (auto &x : strs) cin >> x;
    set<string> st;
    int idx = s - 1, round = 0;
    while (idx < m) {
        if (st.find(strs[idx]) == st.end()) {
            if (round == 0) {
                cout << strs[idx] << '\n';
                st.insert(strs[idx]);
            }
            round = (round + 1) % n;
        }
        ++idx;
    }
    if (st.empty())
        cout << "Keep going..." << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> pairs;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        pairs.emplace_back(a, b);
    }
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        set<int> st;
        for (int j = 0; j < k; ++j) {
            int x; cin >> x;
            st.insert(x);
        }
        auto check = [&]() {
            for (auto &[a, b] : pairs)
                if (st.find(a) != st.end() and st.find(b) != st.end()) return false;
            return true;
        };
        cout << (check() ? "Yes" : "No") << '\n';
    }
    return 0;
}
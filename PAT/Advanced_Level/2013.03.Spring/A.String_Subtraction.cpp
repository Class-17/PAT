#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string a, b;
    getline(cin, a);
    getline(cin, b);
    set<char> st;
    for (auto &ch : b) st.insert(ch);
    string res;
    for (auto &ch : a)
        if (st.find(ch) == st.end())
            res.push_back(ch);
    cout << res << '\n';
    return 0;
}
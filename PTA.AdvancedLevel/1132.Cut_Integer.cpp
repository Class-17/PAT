#include <bits/stdc++.h>
using namespace std;

bool check(int z) {
    string s = to_string(z);
    int len = size(s) / 2;
    int a = stoi(s.substr(0, len));
    int b = stoi(s.substr(len, len));
    if (b == 0) return false;
    return z % (a * b) == 0;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int _; cin >> _;
    while (_--) {
        int x; cin >> x;
        cout << (check(x) ? "Yes" : "No") << '\n';
    }
    return 0;
}
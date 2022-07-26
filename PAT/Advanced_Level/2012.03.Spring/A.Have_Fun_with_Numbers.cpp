#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    auto a = s;
    reverse(begin(a), end(a));
    int rem = 0;
    for (int i = 0; i < size(a); ++i) {
        int curr = (a[i] - '0') * 2 + rem;
        a[i] = curr % 10 + '0';
        rem = curr / 10;
    }
    if (rem) a.push_back(rem + '0');
    reverse(begin(a), end(a));
    auto b = a;
    sort(begin(s), end(s));
    sort(begin(b), end(b));
    cout << (s == b ? "Yes" : "No") << '\n';
    cout << a << '\n';
    return 0;
}
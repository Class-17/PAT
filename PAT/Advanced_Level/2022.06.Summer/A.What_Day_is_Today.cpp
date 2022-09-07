#include <bits/stdc++.h>
using namespace std;

string s1[] =  {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

string s2[] =  {"yesterday", "today", "tomorrow"};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<int> a(3), b(3);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j) {
            int x = (a[i] - i + 1 + 7) % 7;
            int y = (b[j] - j + 1 + 7) % 7;
            if (x != y) continue;
            cout << s1[x] << '\n';
            cout << s2[i] << '\n';
            cout << s2[j] << '\n';
            return 0;
        }
    return 0;
}
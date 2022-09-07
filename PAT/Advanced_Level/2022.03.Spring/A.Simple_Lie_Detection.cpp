#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, t, k;
    cin >> n >> t >> k;
    for (int i = 0; i < k; ++i) {
        string s; cin >> s;
        int val = 0;
        if (s.front() == 'f') val -= 2;
        if (s.back() == 'a') val -= 1;
        for (int i = 0; i < n; ++i)
            if (i + 1 < n and s[i] == 'a' and (s[i + 1] == 'e' or s[i + 1] == 'h')) val -= 4;
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (j < n and s[j] == s[i]) ++j;
            if (j - i > 5) val += 3;
            i = j - 1;
        }
        for (int i = 0; i < n; ++i) {
            int j = i + 1;
            while (j < n and s[j] == s[j - 1] + 1) ++j;
            if (j - i > 3) val += 5;
            i = j - 1;
        }
        cout << val;
        if (val > t) cout << "!!!";
        cout << '\n';
    }
    return 0;
}
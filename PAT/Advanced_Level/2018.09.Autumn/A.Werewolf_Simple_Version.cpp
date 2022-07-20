#include <bits/stdc++.h>
using namespace std;

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    vector<int> seq(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> seq[i];
    auto solve = [&]()->string {
        vector<pair<int, int>> curr(n + 1);
        for (int i = 1; i <= n; ++i) {
            int idx = abs(seq[i]);
            if (seq[i] > 0) ++curr[idx].first;
            else            ++curr[idx].second;
        }
        for (int a = 1; a <= n; ++a)
            for (int b = a + 1; b <= n; ++b) {
                int two = 0;
                int x = abs(seq[a]), y = abs(seq[b]);
                if (seq[a] > 0 and (x == a or x == b)) ++two;
                if (seq[b] > 0 and (y == a or y == b)) ++two;
                if (seq[a] < 0 and (x != a and x != b)) ++two;
                if (seq[b] < 0 and (y != a and y != b)) ++two;
                if (two != 1) continue;
                int liars = 0;
                for (int i = 1; i <= n; ++i) {
                    if (i == a or i == b) liars += curr[i].first;
                    else                  liars += curr[i].second;
                }
                if (liars == 2) return to_string(a) + ' ' + to_string(b);
            }
        return "No Solution";
    };
    cout << solve() << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n; cin >> m >> n;
    unordered_map<int, int> colors;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            int color; cin >> color;
            colors[color]++;
        }
    auto get_dominant_color = [&](int num) {
        for (auto & color : colors)
            if (color.second > num) return color.first;
    };
    cout << get_dominant_color(m * n / 2) << endl;
    return 0;
}
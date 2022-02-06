#include <bits/stdc++.h>
using namespace std;

constexpr int dirs[][3] {{0, 1, 0}, {1, 0, 0}, {0, -1, 0}, {-1, 0, 0}, {0, 0, 1}, {0, 0, -1}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int m, n, l, t;
    cin >> m >> n >> l >> t;
    vector<vector<vector<int>>> brain(l, vector<vector<int>>(m, vector<int>(n)));
    for (auto &slice : brain)
        for (auto &row : slice)
            for (auto &x : row)
                cin >> x;
    auto check = [&](int x, int y, int z) {
        if (x < 0 || x >= m || y < 0 || y >= n || z < 0 || z >= l) return false;
        return brain[z][x][y] == 1;
    };
    auto bfs = [&](int row, int column, int level) {
        int sum = 1;
        queue<tuple<int, int, int>> collec;
        collec.push({row, column, level});
        brain[level][row][column] = 0;
        while (!collec.empty()) {
            auto [x, y, z] = collec.front();
            collec.pop();
            for (auto &[dx, dy, dz] : dirs) {
                auto [nx, ny, nz] = tuple{x + dx, y + dy, z + dz};
                if (!check(nx, ny, nz)) continue;
                collec.push({nx, ny, nz});
                brain[nz][nx][ny] = 0;
                sum += 1;
            }
        }
        return sum >= t ? sum : 0;
    };
    int volume = 0;
    for (int z = 0; z < l; ++z)
        for (int x = 0; x < m; ++x)
            for (int y = 0; y < n; ++y)
                if (brain[z][x][y]) volume += bfs(x, y, z);
    cout << volume << '\n';
    return 0;
}
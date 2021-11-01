#include <bits/stdc++.h>
using namespace std;

constexpr int dirs[][3] {{0, 0, 1}, {0, 1, 0}, {0, 0, -1}, {0, -1, 0}, {1, 0, 0}, {-1, 0, 0}};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int M, N, L, T;
    cin >> M >> N >> L >> T;
    vector<vector<vector<int>>> brain(L, 
        vector<vector<int>>(M, vector<int>(N)));
    for (auto &slice : brain)
        for (auto &row : slice)
            for (auto &x : row)
                cin >> x;
    auto check = [&](int x, int y, int z) {
        if (x < 0 || x >= M || y < 0 || y >= N || z < 0 || z >= L) return false;
        return brain[z][x][y] == 1;
    };
    auto bfs = [&](int row, int column, int level) {
        int sum = 1;
        deque<tuple<int, int, int>> collec;
        collec.emplace_back(row, column, level);
        brain[level][row][column] = 0;
        while (!collec.empty()) {
            int x, y, z;
            tie(x, y, z) = collec.front();
            collec.pop_front();
            for (auto & dir : dirs) {
                int nx = x + dir[1], ny = y + dir[2], nz = z + dir[0];
                if (!check(nx, ny, nz)) continue;
                collec.emplace_back(nx, ny, nz);
                brain[nz][nx][ny] = 0;
                sum += 1;
            }
        }
        return sum >= T ? sum : 0;
    };
    int volume = 0;
    for (int z = 0; z < L; ++z)
        for (int x = 0; x < M; ++x)
            for (int y = 0; y < N; ++y)
                if (brain[z][x][y]) volume += bfs(x, y, z);
    cout << volume << endl;
    return 0;
}
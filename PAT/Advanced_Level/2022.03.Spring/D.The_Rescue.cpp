#include <bits/stdc++.h>
using namespace std;

constexpr int maxn = 101;

constexpr int inf = 0x3f3f3f3f;

constexpr int dirs[][2] {-1, 0, 0, 1, 1, 0, 0, -1};

int n, m;

vector<string> mat;

class area {
public:
    int r, c;
    string seq;
    int len;
public:
    area(int len = maxn + 1) : len(len) {}
    
    area(int r, int c, string seq) : r(r), c(c), seq(seq), len(size(seq)) {}
    
    bool operator < (const area &x) const {
        if (len == x.len) return seq < x.seq;
        return len > x.len;
    }
};

struct node {
    int r, c;
    string seq;

    node(int r, int c, string seq) : r(r), c(c), seq(seq) {}

    bool operator < (const node &x) const {
        if (size(seq) == size(x.seq)) return seq > x.seq;
        return size(seq) > size(x.seq);
    }
};

pair<int, int> get_s() {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            if (mat[i][j] == 'X') return {i, j};
    return {-1, -1};
}

bool comp(const string &a, const string &b) {
    if (size(a) == size(b)) return a < b;
    return size(a) < size(b);
}

constexpr int mp[] {2, 3, 0, 1};

vector<vector<string>> dijkstra() {
    auto [sr, sc] = get_s();
    vector<vector<string>> res(n, vector<string>(m));
    priority_queue<node> pq;
    pq.emplace(sr, sc, "");
    while (!pq.empty()) {
        auto [r, c, seq] = pq.top(); pq.pop();
        if (comp(res[r][c], seq)) continue;
        for (int d = 0; d < 4; ++d) {
            auto [nr, nc] = pair{r + dirs[d][0], c + dirs[d][1]};
            if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
            if (mat[nr][nc] == '#' or mat[nr][nc] == 'X') continue;
            string curr;
            curr.push_back(mp[d] + '0');
            curr += seq;
            if (res[nr][nc].empty() or comp(curr, res[nr][nc])) {
                res[nr][nc] = curr;
                pq.emplace(nr, nc, curr);
            }
        }
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cin >> n >> m;
    mat = vector<string>(n);
    for (auto &s : mat) cin >> s;
    vector<vector<area>> mp(n, vector<area>(m));
    set<area> areas;
    set<pair<int, int>> ps;
    auto sqs = dijkstra();
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (mat[i][j] == 'X' or mat[i][j] == '#') continue;
            mp[i][j] = area(i, j, sqs[i][j]);
            areas.insert(mp[i][j]);
            ps.emplace(i, j);
        }
    string res;
    while (!areas.empty()) {
        const string seq = begin(areas)->seq;
        res += seq;
        ps.clear();
        for (auto &x : areas) {
            int r = x.r, c = x.c;
            for (auto &d : seq) {
                if (mat[r][c] == 'X') break;
                int nr = r + dirs[d - '0'][0];
                int nc = c + dirs[d - '0'][1];
                if (nr < 0 or nr >= n or nc < 0 or nc >= m) continue;
                if (mat[nr][nc] == '#') continue;
                tie(r, c) = pair{nr, nc};
            }
            if (mat[r][c] != 'X')
                ps.emplace(r, c);
        }
        areas.clear();
        for (auto &[r, c] : ps)
            areas.insert(mp[r][c]);
    }
    cout << res << '\n';
    return 0;
}
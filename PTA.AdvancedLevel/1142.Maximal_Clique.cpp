#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int nv, ne;
    cin >> nv >> ne;
    vector<vector<int>> g(nv + 1, vector<int>(nv + 1));
    for (int i = 1; i <= nv; ++i)
        g[i][i] = 1;
    for (int i = 0; i < ne; ++i) {
        int a, b;
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; ++i) {
        int k; cin >> k;
        vector<int> curr(nv + 1, 1);
        vector<int> res(nv + 1, 0);
        for (int i = 0; i < k; ++i) {
            int x;
            cin >> x;
            for (int j = 1; j <= nv; ++j)
                curr[j] &= g[x][j];
            res[x] = 1;
        }
        auto check = [&]() {
            for (int i = 1; i <= nv; ++i) {
                if (curr[i] == 0 && res[i] == 1)
                    return "Not a Clique";
            }
            for (int i = 1; i <= nv; ++i)
                if (curr[i] == 1 && res[i] == 0) 
                    return "Not Maximal";
            return "Yes";
        };
        cout << check() << endl;
    }
    return 0;
}
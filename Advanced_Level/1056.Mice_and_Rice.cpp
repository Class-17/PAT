#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> w(n);
    for (auto & x : w) cin >> x;
   	deque<int> seq;
    for (int i = 0; i < n; ++i) {
        int num; cin >> num;
        seq.push_back(num);
    }
    vector<int> ranks(n);
    auto game = [&]()->void {
        int group = ceil(size(seq) / double(m)), len = size(seq);
        for (int i = 0; i < group && len > 0; ++i) {
            int winner = seq.front();
            for (int j = 0; j < m && len > 0; ++j) {
                auto x = seq.front();
                ranks[x] = group + 1;
                if (w[x] > w[winner]) winner = x;
                seq.pop_front();
                len--;
            }
            seq.push_back(winner);
        }
    };
    while (size(seq) > 1) game();
    ranks[seq.front()] = 1; 
    for (int i = 0; i < n; ++i)
        cout << ranks[i] << (i + 1 < n ? ' ' : '\n');
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<int> seq(n);
    for(auto& x : seq) cin >> x;
    bitset<int(1e5) + 1> memo;
    int total = 0;
    auto check = [&](int p) {
        if(memo[p] || seq[p] == p) return 0;
        int cnt = 1, i = p;
        do {
            if(seq[i] != 0) cnt++;
            else            cnt--;
            memo[i] = true;
            i = seq[i];
        } while (i != p);
        return cnt;
    };
    for(int i = 0; i < seq.size(); i++)
        total += check(i);
    cout << total << '\n';
    return 0;
}
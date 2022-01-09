#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    vector<string> segs(n);
    for(auto& seg : segs) cin >> seg;
    sort(segs.begin(), segs.end(), [](const auto& a, auto& b) {
        return a + b < b + a;});
    string ans;
    for(auto& seg : segs) ans += seg;
    while (ans.size() > 1 && ans[0] == '0')
        ans.erase(ans.begin());
    cout << ans << '\n';
    return 0;
}
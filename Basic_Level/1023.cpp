#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<int> cnt(10);
    string num; cin >> num;
    for (auto & ch : num) cnt[ch - '0']++;
    int cast = 0;
    auto check = [&]() {
        for (int i = num.size() - 1; i >= 0; --i) {
            int val = (num[i] - '0') * 2 + cast; 
            num[i] = val % 10 + '0';
            cnt[val % 10]--;
            cast = val / 10;
        }
        if (cast > 0) {
            num.insert(0, 1, cast + '0');
            return false;
        }
        for (int i = 0; i < 10; ++i)
            if (cnt[i] != 0) return false;
        return true;
    };
    cout << (check() ? "Yes\n" : "No\n") << num << endl;
    return 0;
}
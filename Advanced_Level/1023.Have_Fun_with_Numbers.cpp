#include <bits/stdc++.h>
using namespace std;

bool check(string &num) {
    vector<int> cnt(10);
    int cast = 0;
    for (int i = int(size(num)) - 1; i >= 0; --i) {
        int val = (num[i] - '0') * 2 + cast; 
        cnt[num[i] - '0']++;
        cnt[val % 10]--;
        num[i] = val % 10 + '0';
        cast = val / 10;
    }
    if (cast > 0) {
        num.insert(0, 1, cast + '0');
        return false;
    }
    for (int i = 0; i < 10; ++i)
        if (cnt[i] != 0) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string num; cin >> num;
    cout << (check(num) ? "Yes\n" : "No\n") << num << endl;
    return 0;
}
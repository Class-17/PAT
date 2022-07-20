#include <bits/stdc++.h>
using namespace std;

int transe(string &num, int k) {
    for (int i = 0; i < k; i++) {
        auto revn = num;
        reverse(begin(revn), end(revn));
        if (num == revn) return i;
        int cast = 0;
        for (int i = int(size(num)) - 1; i >= 0; --i) {
            int val = num[i] - '0' + revn[i] - '0' + cast;
            num[i] = val % 10 + '0';
            cast = val / 10;
        }
        if (cast > 0) num.insert(0, 1, cast + '0');
    }
    return k;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string num;
    int k;
    cin >> num >> k;
    int res = transe(num, k);
    cout << num << '\n' << res << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    int pre = 0, sum = 0;
    for (int i = 0; i < n; ++i) {
        int curr; cin >> curr;
        if (curr > pre)
            sum += (curr - pre) * 6 + 5;
        else
            sum += (pre - curr) * 4 + 5;
        pre = curr;
    }
    cout << sum << '\n';
    return 0;
}
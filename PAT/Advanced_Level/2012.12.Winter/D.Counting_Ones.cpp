#include <bits/stdc++.h>
using namespace std;

int count(const int &n, const int &x) {
    string num = to_string(n);
    int len = size(num);
    int res = 0;
    for (int i = 0; i < len; ++i) {
        int hi = (i ? stoi(num.substr(0, i)) + 1 : 1);
        int lo = pow(10, len - 1 - i);
        if (num[i] - '0' > x)
            res += pow(10, len - 1 - i);
        else if (num[i] - '0' == x)
            res += (i + 1 < len ? stoi(num.substr(i + 1)) + 1 : 1);
        res += (hi - 1) * lo;
    }
    return res;
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    cout << count(n, 1) << '\n';
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string n; cin >> n;
    int cnt = 0, len = size(n);
    for (int i = 0; i < len; ++i) {
        int left = (i > 0 ? stoi(n.substr(0, i)) : 0) + 1;
        int right = (i + 1 < len ? stoi(n.substr(i + 1)) : 0) + 1;
        cnt += (left - 1) * pow(10, len - i - 1);
        if (n[i] == '1')
            cnt += right;
        else if (n[i] > '1') 
            cnt += pow(10, len - i - 1);
    }
    cout << cnt << '\n';
    return 0;
}
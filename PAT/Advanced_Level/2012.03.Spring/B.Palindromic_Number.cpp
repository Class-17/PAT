#include <bits/stdc++.h>
using namespace std;

string multi(const string &a) {
    auto b = a;
    reverse(begin(b), end(b));
    int rem = 0;
    for (int i = 0; i < size(b); ++i) {
        int val = a[i] - '0' + b[i] - '0' + rem;
        b[i] = val % 10 + '0';
        rem = val / 10;
    }
    if (rem) b.push_back(rem + '0');
    reverse(begin(b), end(b));
    return b;
}

bool isPalindromic(const string &s) {
    int n = size(s);
    for (int i = 0; i < n / 2; ++i)
        if (s[i] != s[n - 1 - i]) return false;
    return true;
}

pair<string, int> solve(string num, int k) {
    for (int i = 0; i < k; ++i) {
        if (isPalindromic(num)) return {num, i};
        num = multi(num);
    }
    return {num, k};
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string num;
    int k;
    cin >> num >> k;
    auto [val, cnt] = solve(num, k);
    cout << val << '\n' << cnt << '\n';
    return 0;
}
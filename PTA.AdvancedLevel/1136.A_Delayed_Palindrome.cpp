#include <bits/stdc++.h>
using namespace std;

constexpr int lim = 10;

string f(string a) {
    auto b = a;
    reverse(begin(b), end(b));
    cout << a << " + " << b << " = ";
    int rem = 0;
    for (int i = 0; i < size(a); ++i) {
        int curr = a[i] - '0' + b[i] - '0' + rem;
        a[i] = curr % 10 + '0';
        rem = curr / 10;
    }
    if (rem) a.push_back(rem + '0');
    reverse(begin(a), end(a));
    cout << a << '\n';
    return a;
}

bool isPalindromic(const string &s) {
    int n = size(s);
    for (int i = 0; i < n / 2; ++i)
        if (s[i] != s[n - i - 1]) return false;
    return true;
}

bool solve(string s) {
    for (int i = 0; i < lim and !isPalindromic(s); ++i)
        s = f(s);
    if (isPalindromic(s))
        cout << s << " is a palindromic number." << '\n';
    return isPalindromic(s);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string s; cin >> s;
    if (!solve(s))
        cout << "Not found in 10 iterations." << '\n';
    return 0;
}
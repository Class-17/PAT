#include <bits/stdc++.h>
using namespace std;

int is_prime(int x) {
    if (x < 2) return false;
    for (int i = 2; i * i <= x; ++i)
        if (x % i == 0) return false;
    return true;
}

string f(const string &s, int k) {
    for (int i = 0; i + k <= size(s); ++i) {
        auto x = s.substr(i, k);
        if (is_prime(stoi(x))) return x;
    }
    return "404";
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    cout << f(s, k) << '\n';
    return 0;
}
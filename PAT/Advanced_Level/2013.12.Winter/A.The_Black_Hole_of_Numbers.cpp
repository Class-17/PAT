#include <bits/stdc++.h>
using namespace std;

int getMin(int x) {
    string s = to_string(x);
    while (size(s) < 4) s.push_back('0');
    sort(begin(s), end(s));
    return stoi(s);
}

int getMax(int x) {
    string s = to_string(x);
    while (size(s) < 4) s.push_back('0');
    sort(rbegin(s), rend(s));
    return stoi(s);
}

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n; cin >> n;
    do {
        n = getMax(n);
        int m = getMin(n);
        cout << setw(4) << setfill('0') << n << " - ";
        cout << setw(4) << setfill('0') << m << " = ";
        cout << setw(4) << setfill('0') << n - m << "\n";
        n = n - m;
    } while (n and n != 6174);
    return 0;
}
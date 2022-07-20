#include <bits/stdc++.h>
using namespace std;

string count(string &d) {
    string res;
    for (int i = 0; i < size(d); ++i) {
        int np = i + 1;
        while (np < size(d) && d[np] == d[i]) np++;
        res += d[i] + to_string(np - i);
        i = np - 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string d;
    int n;
    cin >> d >> n;
    for (int i = 1; i < n; ++i)
        d = count(d);
    cout << d << endl;
    return 0;
}
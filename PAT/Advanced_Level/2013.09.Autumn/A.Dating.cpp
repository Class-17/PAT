#include <bits/stdc++.h>
using namespace std;

const string days[] {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    int n = min(size(a), size(b));
    int m = min(size(c), size(d));
    int day, hh, mm;
    for (int i = 0; i < n; ++i) {
        if (a[i] != b[i]) continue;
        if (a[i] < 'A' or a[i] > 'A' + 6) continue;
        day = a[i] - 'A';
        for (int j = i + 1; j < n; ++j) {
            if (a[j] != b[j]) continue;
            if (!isdigit(a[j]) and (a[j] < 'A' or a[j] > 'N')) continue;
            hh = (isdigit(a[j]) ? a[j] - '0' : b[j] - 'A' + 10);
            break;
        }
        break;
    }
    for (int i = 0; i < m; ++i) {
        if (c[i] != d[i] or !isalpha(c[i])) continue;
        mm = i;
        break;
    }
    cout << days[day] << ' ';
    cout << setw(2) << setfill('0') << hh << ':';
    cout << setw(2) << setfill('0') << mm << '\n';
    return 0;
}
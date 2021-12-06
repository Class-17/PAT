#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string a;
    int b;
    cin >> a >> b;
    int last = 0;
    for (int i = 0; i < a.size(); ++i) {
        int num = a[i] - '0' + last * 10;
        a[i] = num / b + '0';
        last = num % b;
    }
    if (a[0] == '0' && a.size() > 1) a.erase(a.begin());
    cout << a << " " << last << endl;
    return 0;
}
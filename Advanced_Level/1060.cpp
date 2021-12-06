#include <bits/stdc++.h>
using namespace std;

string chop(string num, int n) {
    int exp = 0;
    while(num.size() > 0 && *begin(num) == '0')
        num.erase(begin(num));
    if (num.size() > 0 && *begin(num) != '.') {
        for (int i = 0; i < num.size(); ++i) {
            if (num[i] != '.') exp++;
            else {
                num.erase(begin(num) + i);
                break;
            }
        }
    }
    else if (num.size() > 0 && num[0] == '.') {
        num.erase(begin(num));
        while (num.size() > 0 && *begin(num) == '0') {
            num.erase(begin(num));
            exp--;
        }
    }
    if (num.size() == 0) exp = 0;
    num.resize(n, '0');
    return "0." + num + "*10^" + to_string(exp);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string a, b;
    cin >> n >> a >> b;
    a = chop(a, n);
    b = chop(b, n);
    if (a == b)      cout << "YES " << a << endl;
    else  cout << "NO " << a << " " << b << endl;
    return 0;
}
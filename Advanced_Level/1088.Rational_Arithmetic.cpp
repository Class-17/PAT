#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void print(ll x, ll y) {
    if (y == 0) {
        cout << "Inf";
        return;
    }
    if (x < 0)  cout << '(';
    if (y == 1) cout << x;
    else if (abs(x) > y)
        cout << x / y << ' ' << abs(x) % y << '/' << y;
    else
        cout << x << '/' << y;
    if (x < 0) cout << ')';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll xa, ya, xb, yb, xz, yz;
    char op;
    cin >> xa >> op >> ya >> xb >> op >> yb;
    tie(xa, ya) = pair{xa / abs(__gcd(xa, ya)), ya / abs(__gcd(xa, ya))};
    tie(xb, yb) = pair{xb / abs(__gcd(xb, yb)), yb / abs(__gcd(xb, yb))};
    string seq = "+-*/";
    auto add = [&]() {
        xz = xa * yb + ya * xb;
        yz = ya * yb;
    };
    auto minu = [&]() {
        xz = xa * yb - ya * xb;
        yz = ya * yb;
    };
    auto multi = [&]() {
        xz = xa * xb;
        yz = ya * yb;
    };
    auto divide = [&]() {   
        if (yz == 0) return;
        xz = (xa * xb < 0 ? -abs(xa * yb) : abs(xa * yb));
        yz = abs(ya * xb);
    };
    for (auto &ch : seq) {
        if (ch == '+') add();
        else if (ch == '-') minu();
        else if (ch == '*') multi();
        else if (ch == '/') divide();
        tie(xz, yz) = pair{xz / abs(__gcd(xz, yz)), yz / abs(__gcd(xz, yz))};
        print(xa, ya); cout << string{' ', ch, ' '};
        print(xb, yb); cout << " = ";
        print(xz, yz); cout << '\n';
    }
    return 0;
}
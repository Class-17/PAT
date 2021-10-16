#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int charToInt(char c) {
    return c > '9' ? c - 'a' + 10 : c - '0';
}

ll toDec(ll radix, const string& s) {
    ll ans = 0;
    for(ll i = 0; i < s.size(); i++)
        ans = ans * radix + charToInt(s[i]);
    return ans;
}

ll binarySearch(string n, ll lo, ll hi, ll obj) {
    while (lo <= hi) {
        ll mid = lo + (hi - lo) / 2; 
        ll decN = toDec(mid, n);
        if(decN > obj || decN < 0) hi = mid - 1; 
        else if(decN < obj)        lo = mid + 1;
        else                return mid;
    }
    return -1;
}

int main()
{
    string s1, s2;
    ll tag, radix;
    cin >> s1 >> s2 >> tag >> radix;
    if(tag == 2) s1.swap(s2);
    ll n1 = toDec(radix, s1);
    ll lo = charToInt(*max_element(s2.begin(), s2.end())) + 1;
    ll hi = max(n1, lo) + 1;
    ll res = binarySearch(s2, lo, hi, n1);
    cout << (res != -1 ? to_string(res) + "\n" : "Impossible\n");
    return 0;
}
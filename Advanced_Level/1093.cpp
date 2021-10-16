#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

int countPAT(string& s) {
    int P = 0, PA = 0, PAT = 0;
    for (char& c : s) {
        if(c == 'P') P = P + 1;
        if(c == 'A') PA = (PA + P) % MOD;
        if(c == 'T') PAT = (PAT + PA) % MOD;
    }
    return PAT;
}

int main()
{   
    string s;
    cin >> s;
    cout << countPAT(s) << endl;
    return 0;
}
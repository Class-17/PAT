#include <bits/stdc++.h>
using namespace std;

int checkPassword(string s) {
    if(s.size() < 6) return 1;
    bool hasLetter = false, hasDigit = false;
    for(char c : s) {
        if(isalpha(c))      hasLetter = true;
        else if(isdigit(c)) hasDigit = true;
        else if(c != '.')   return 2;
    }
    if(hasDigit == false) return 3;
    if(hasLetter == false) return 4;
    return 0;
}

int main()
{
    int N;
    cin >> N;
    getchar();
    while (N--) {
        string s;
        getline(cin, s);
        switch (checkPassword(s)) {
            case 0: cout << "Your password is wan mei.\n"; break;
            case 1: cout << "Your password is tai duan le.\n"; break;
            case 2: cout << "Your password is tai luan le.\n"; break;
            case 3: cout << "Your password needs shu zi.\n"; break;
            case 4: cout << "Your password needs zi mu.\n"; break;
        }
    }
    return 0;
}
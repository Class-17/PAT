#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);  
    unordered_map<string, int> digit = {{"tret", 0}, {"jan", 1}, {"feb", 2}, {"mar", 3}, {"apr", 4}, 
                                        {"may", 5}, {"jun", 6}, {"jly", 7}, {"aug", 8}, 
                                        {"sep", 9}, {"oct", 10}, {"nov", 11}, {"dec", 12}};
    unordered_map<string, int> higher_digit = {{"tam", 1}, {"hel", 2}, {"maa", 3}, {"huh", 4}, 
                                        {"tou", 5}, {"kes", 6}, {"hei", 7}, {"elo", 8}, 
                                        {"syy", 9}, {"lok", 10}, {"mer", 11}, {"jou", 12}};
    vector<string> mars_digit = {"tret", "jan", "feb", "mar", "apr", "may", "jun", 
                                 "jly", "aug", "sep", "oct", "nov", "dec"};
    vector<string> mars_higher_digit = {"tret", "tam", "hel", "maa", "huh", "tou", "kes", 
                                        "hei", "elo", "syy", "lok", "mer", "jou"};                  
    int n; (cin >> n).get(); 
    while (n--) {
        string s; getline(cin, s);
        if (isdigit(s[0])) {
            int num = stoi(s);
            if (num / 13 > 0)
                cout << mars_higher_digit[num / 13];
            if (num / 13 > 0 && num % 13 > 0) cout << " ";
            if (num % 13 != 0 || num == 0)
                cout << mars_digit[num % 13];
            cout << '\n';
        }
        else {
            int num = 0;
            string val = s.substr(0, 3);
            if (higher_digit.find(val) != higher_digit.end())
                num += higher_digit[val] * 13;
            if (num > 0) 
                val = size(s) > 3 ? s.substr(4, 3) : " ";
            if (digit.find(val) != digit.end())
                num += digit[val];
            cout << num << '\n';
        }
    }
    return 0;
}
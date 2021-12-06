#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s; getline(cin, s);
    map<string, int> collec;
    for (int p = 0; p < s.size(); ++p) {
        int next_pos = p;
        while (next_pos < s.size() && 
               (isalpha(s[next_pos]) || isdigit(s[next_pos]))) next_pos++;
        string word;
        for (int i = p; i < next_pos; ++i)
            if (isalpha(s[i])) word.push_back(tolower(s[i]));
            else if (isdigit(s[i])) word.push_back(s[i]);
        p = next_pos;
        if (word.size() > 0) collec[word]++;
    }
    auto get_pattern = [&]() {
        int max_cnt = 0;
        string pattern;
        for (auto & word : collec)
            if (word.second > max_cnt) {
                max_cnt = word.second;
                pattern = word.first;
            }
        return pattern + " " + to_string(max_cnt);
    };
    cout << get_pattern() << endl;
    return 0;
}
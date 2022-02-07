#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    getline(cin, s);
    int n = size(s);
    map<string, int> collec;
    for (int p = 0; p < n; ++p) {
        int next_pos = p;
        while (next_pos < n && (isalpha(s[next_pos]) || isdigit(s[next_pos]))) next_pos++;
        string word;
        for (int i = p; i < next_pos; ++i)
            if (isalpha(s[i]))      word.push_back(tolower(s[i]));
            else if (isdigit(s[i])) word.push_back(s[i]);
        p = next_pos;
        if (size(word) > 0) collec[word]++;
    }
    auto get_pattern = [&]() {
        pair<string, int> res{"", 0};
        for (auto &word : collec)
            if (word.second > res.second) res = word;
        return res.first + " " + to_string(res.second);
    };
    cout << get_pattern() << '\n';
    return 0;
}
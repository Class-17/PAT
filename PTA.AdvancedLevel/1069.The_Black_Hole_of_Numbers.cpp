#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string num; cin >> num;
    do {
        while (num.size() < 4) num.insert(num.begin(), 1, '0');
        sort(num.begin(), num.end(), greater<>());
        int max_val = stoi(num);
        sort(num.begin(), num.end());
        int min_val = stoi(num);
        num = to_string(max_val - min_val);
        cout << setw(4) << setfill('0') << max_val << " - ";
        cout << setw(4) << setfill('0') << min_val << " = "; 
        cout << setw(4) << setfill('0') << max_val - min_val << '\n';
    } while(num != "6174" && num != "0");
    return 0;
}
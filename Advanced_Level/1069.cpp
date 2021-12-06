#include <bits/stdc++.h>
using namespace std;
int main()
{
    string num;
    cin >> num;
    do {
        while (num.size() < 4) num.insert(num.begin(), 1, '0');
        sort(num.begin(), num.end(), greater<char>());
        int max = stoi(num);
        sort(num.begin(), num.end());
        int min = stoi(num);
        num = to_string(max - min);
        cout << setw(4) << setfill('0') << max << " - ";
        cout << setw(4) << setfill('0') << min << " = "; 
        cout << setw(4) << setfill('0') << max - min << endl;
    } while(num != "6174" && num != "0");
    return 0;
}
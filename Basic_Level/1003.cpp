#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cin >> num;
    getchar();
    while(num--)
    {
        string s;
        cin >> s;
        int a = 0, b = 0, c = 0, i = 0;
        int len = s.size();
        while (i < len && s[i++] == 'A') a++;
        while (i < len && s[i] != 'A') i++;
        while (i < len && s[i++] == 'A') b++;
        while (i < len && s[i] != 'A') i++;
        while (i < len && s[i++] == 'A') c++;
        if((a + b + c) != (len - 2) || a * b != c || s[a] != 'P' || s[a + b + 1] != 'T' || b == 0)
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";     
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main()
{
    string A, B;
    char Da, Db;
    cin >> A >> Da >> B >> Db;
    int i = 0;
    while (i < A.size()) {
        if(A[i] != Da) 
            A.erase(A.begin() + i);
        else i++;
    }
    i = 0;
    while (i < B.size()) {
        if(B[i] != Db)
            B.erase(B.begin() + i);
        else i++;
    }
    cout << atoi(A.c_str()) + atoi(B.c_str()) << endl;
    return 0;
}
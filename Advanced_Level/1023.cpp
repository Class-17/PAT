/*

1023 Have Fun with Numbers (20point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

Notice that the number 123456789 is a 9-digit number consisting exactly the 
numbers from 1 to 9, with no duplication. Double it we will obtain 246913578, 
which happens to be another 9-digit number consisting exactly the numbers from 
1 to 9, only in a different permutation. Check to see the result if we double it again!

Now you are suppose to check if there are more numbers with this property. That is, 
double a given number with k digits, you are to tell if the resulting number consists 
of only a permutation of the digits in the original number.
Input Specification:

Each input contains one test case. Each case contains one positive integer with no 
more than 20 digits.

Output Specification:

For each test case, first print in a line "Yes" if doubling the input number gives a number 
that consists of only a permutation of the digits in the original number, or "No" if not. 
Then in the next line, print the doubled number.

Sample Input:

1234567899

Sample Output:

Yes
2469135798

*/

#include <bits/stdc++.h>
using namespace std;

const int MAXN = 20;
int N[MAXN], len = 0;
int hashTable[10];

int main()
{
    string s;
    cin >> s;
    for(int i = s.size() - 1; i >= 0; i--)
    {
        N[len] = s[i] - '0'; 
        hashTable[N[len]]++;
        N[len++] *= 2;
    }
    for(int i = 0; i < len; i++)
    {
        N[i + 1] += N[i] / 10;
        N[i] %= 10; 
        hashTable[N[i]]--;
    }
    if(N[len] != 0)
    {
        cout << "No\n";
        for(int i = len; i >= 0; i--)
            cout << N[i];
        cout << endl;
    }
    else
    {
        for(int i = 0; i < 10; i++)
            if(hashTable[i] != 0)
                {
                    cout << "No\n";
                    break;
                }
            else if(i == 9)
                cout << "Yes\n";
        for(int i = len - 1; i >= 0; i--)
            cout << N[i];
    } 
    return 0;
}
/*

1096 Consecutive Factors (20point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

Among all the factors of a positive integer N, there may exist 
several consecutive numbers. For example, 630 can be factored as 
3×5×6×7, where 5, 6, and 7 are the three consecutive numbers. Now 
given any positive N, you are supposed to find the maximum number of 
consecutive factors, and list the smallest sequence of the consecutive factors.
Input Specification:

Each input file contains one test case, which gives the integer N (1<N<2​31​​).

Output Specification:

For each test case, print in the first line the maximum number of consecutive 
factors. Then in the second line, print the smallest sequence of the consecutive 
factors in the format factor[1]*factor[2]*...*factor[k], where the factors are 
listed in increasing order, and 1 is NOT included.

Sample Input:

630

Sample Output:

3
5*6*7

*/

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, longest = 0, start = 0, end = 0;
    cin >> n;
    for(int i = 2; i <= sqrt(n) + 100; i++)
    {
        if(n % i == 0)
        {
            int temp = i, record = n;
            while(record % temp == 0) {record /= temp; temp++;}
            if(temp - i > longest)
            {
                start = i;
                end = temp;
                longest = temp - i;
            } 
        }
    }
    if(longest == 0) {cout << 1 << endl << n; return 0;}
    cout << longest << endl;
    for(int i = start; i < end; i++)
        cout << i << (i < end - 1 ? "*" : "\n");
    return 0;
}
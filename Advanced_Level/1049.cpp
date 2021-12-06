/*

1049 Counting Ones (30point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

The task is simple: given any positive integer N, you are supposed 
to count the total number of 1's in the decimal form of the integers 
from 1 to N. For example, given N being 12, there are five 1's in 
1, 10, 11, and 12.

Input Specification:

Each input file contains one test case which gives the positive N (≤2​30​​).
Output Specification:

For each test case, print the number of 1's in one line.
Sample Input:

12

Sample Output:

5

*/

#include <iostream>
using namespace std;
int main()
{
    int n, Tpow = 1, total = 0;
    cin >> n;
    while (n / Tpow)
    {
        int Tleft  = n / (Tpow * 10);
        int Tobj   = n / Tpow % 10;
        int Tright = n % Tpow;
        if(Tobj > 1) total += (Tleft + 1) * Tpow;
        else         total += (Tleft) * Tpow + (Tright + 1) * Tobj;
        Tpow *= 10;
    }
    cout << total << endl;
    return 0;
}
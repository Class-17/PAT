/*

1059 Prime Factors (25point(s))

Code Size Limit 16 KB   Time Limit 200 ms  Memory Limit 64 MB

Given any positive integer N, you are supposed to find all of its 
prime factors, and write them in the format N = p​1^​​​k​1​​​​×p​2^​​​k​2​​​​×⋯×p​m^​​​k​m​​​​.
Input Specification:

Each input file contains one test case which gives a positive integer 
N in the range of long int.
Output Specification:

Factor N in the format N = p​1​​^k​1​​*p​2​​^k​2​​*…*p​m​​^k​m​​, where p​i​​'s are prime 
factors of N in increasing order, and the exponent k​i​​ is the number of 
p​i​​ -- hence when there is only one p​i​​, k​i​​ is 1 and must NOT be printed out.
Sample Input:

97532468

Sample Output:

97532468=2^2*11*17*101*1291

*/


#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;

int prime[MAXN], len = 0;

struct factor{
    int x, cnt;
}fac[10];

bool isPrime(int n)
{
    if(n <= 1) return false;
    for(int i = 2; i <= sqrt(n); i++)
        if(n % i == 0) return false;
    return true;
}

void FindPrime()
{
    for(int i = 2; i < MAXN; i++)
        if(isPrime(i))
            prime[len++] = i;
}

int main()
{
    FindPrime();
    long long n,num = 0;
    cin >> n;
    int Tsqrt = sqrt(n);
    if(n == 1) {cout << "1=1\n"; return 0;}
    cout << n << "=";
    for(int i = 0; i < len && i < Tsqrt; i++)
    {   
        if(n % prime[i] == 0)
        {
            fac[num].x = prime[i];
            fac[num].cnt = 0;
            while (n % prime[i] == 0)
            {
                fac[num].cnt++;
                n /= prime[i];
            }
            num++;
        }
    }
    if(n != 1)
    {
        fac[num].x = n;
        fac[num++].cnt = 1;
    }
    for(int i = 0; i < num; i++)
    {
        cout << fac[i].x;
        if(fac[i].cnt > 1)
            cout << "^" << fac[i].cnt;
        cout << (i != num - 1 ? "*" : "\n");
    }
    return 0;
}
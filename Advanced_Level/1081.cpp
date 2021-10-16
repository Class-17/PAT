/*

1081 Rational Sum (20point(s))

Code Size Limit 16 KB   Time Limit 400 ms  Memory Limit 64 MB

Given N rational numbers in the form numerator/denominator, you 
are supposed to calculate their sum.
Input Specification:

Each input file contains one test case. Each case starts with a 
positive integer N (≤100), followed in the next line N rational 
numbers a1/b1 a2/b2 ... where all the numerators and denominators 
are in the range of long int. If there is a negative number, then 
the sign must appear in front of the numerator.

Output Specification:

For each test case, output the sum in the simplest form integer 
numerator/denominator where integer is the integer part of the sum, 
numerator < denominator, and the numerator and the denominator have 
no common factor. You must output only the fractional part if the 
integer part is 0.

Sample Input 1:

5
2/5 4/15 1/30 -2/60 8/3

Sample Output 1:

3 1/3

Sample Input 2:

2
4/3 2/3

Sample Output 2:

2

Sample Input 3:

3
1/3 -1/6 1/8

Sample Output 3:

7/24

*/

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

struct Fraction
{
    ll numtor, dentor;
}sum, Tnext;

Fraction reduction(Fraction temp)
{
    if(temp.dentor < 0)
    {
        temp.numtor *= -1;
        temp.dentor *= -1;
    }
    if(temp.numtor == 0 || temp.dentor == 0)
    {
        temp.numtor = 0;
        temp.dentor = 1;
    }
    ll Tgcd = gcd(abs(temp.numtor), temp.dentor);
    temp.numtor /= Tgcd;
    temp.dentor /= Tgcd;
    return temp;
}

void numAdd()
{
    sum.numtor = sum.numtor * Tnext.dentor + sum.dentor * Tnext.numtor;
    sum.dentor = sum.dentor * Tnext.dentor;
    sum = reduction(sum);
}

int main()
{
    int n;
    scanf("%d", &n);
    sum.numtor = 0; sum.dentor = 1;
    while(n--)
    {
        scanf("%lld/%lld", &Tnext.numtor, &Tnext.dentor);
        Tnext = reduction(Tnext);
        numAdd();
    }
    if(sum.dentor == 1)
        printf("%lld\n", sum.numtor);
    else if(abs(sum.numtor) > sum.dentor) 
        printf("%lld %lld/%lld\n", sum.numtor / sum.dentor, sum.numtor % sum.dentor, sum.dentor);
    else
        printf("%lld/%lld\n", sum.numtor, sum.dentor);
    return 0;
}
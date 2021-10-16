/*

1088 Rational Arithmetic (20point(s))

Code Size Limit 16 KB   Time Limit 200 ms  Memory Limit 64 MB

For two rational numbers, your task is to implement the basic arithmetics, 
that is, to calculate their sum, difference, product and quotient.
Input Specification:

Each input file contains one test case, which gives in one line the two rational 
numbers in the format a1/b1 a2/b2. The numerators and the denominators are all 
in the range of long int. If there is a negative sign, it must appear only in 
front of the numerator. The denominators are guaranteed to be non-zero numbers.
Output Specification:

For each test case, print in 4 lines the sum, difference, product and quotient 
of the two rational numbers, respectively. The format of each line is number1 
operator number2 = result. Notice that all the rational numbers must be in their 
simplest form k a/b, where k is the integer part, and a/b is the simplest fraction 
part. If the number is negative, it must be included in a pair of parentheses. If 
the denominator in the division is zero, output Inf as the result. It is guaranteed 
that all the output integers are in the range of long int.

Sample Input 1:

2/3 -4/2

Sample Output 1:

2/3 + (-2) = (-1 1/3)
2/3 - (-2) = 2 2/3
2/3 * (-2) = (-1 1/3)
2/3 / (-2) = (-1/3)

Sample Input 2:

5/3 0/6

Sample Output 2:

1 2/3 + 0 = 1 2/3
1 2/3 - 0 = 1 2/3
1 2/3 * 0 = 0
1 2/3 / 0 = Inf

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
}x, y, z;

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

void add()
{
    z.numtor = x.numtor * y.dentor + x.dentor * y.numtor;
    z.dentor = x.dentor * y.dentor;
    z = reduction(z);
}

void minu()
{
    z.numtor = x.numtor * y.dentor - x.dentor * y.numtor;
    z.dentor = x.dentor * y.dentor;
    z = reduction(z);
}

void multi()
{
    z.numtor = x.numtor * y.numtor;
    z.dentor = x.dentor * y.dentor;
    z = reduction(z);
}

void divide()
{   
    if(y.numtor == 0) 
    {
        z.numtor = z.dentor = 0;
        return;
    }
    z.numtor = x.numtor * y.dentor;
    z.dentor = x.dentor * y.numtor;
    z = reduction(z);
}

void print(Fraction obj)
{
    if(obj.numtor < 0)  printf("(");
    if(obj.dentor == 1)
        printf("%lld", obj.numtor);
    else if(abs(obj.numtor) > obj.dentor) 
        printf("%lld %lld/%lld", obj.numtor / obj.dentor, abs(obj.numtor) % obj.dentor, obj.dentor);
    else
        printf("%lld/%lld", obj.numtor, obj.dentor);
    if(obj.numtor < 0)  printf(")");
}

int main()
{
    scanf("%lld/%lld %lld/%lld", &x.numtor, &x.dentor, &y.numtor, &y.dentor);
    x = reduction(x);
    y = reduction(y);
    add();      print(x); printf(" + "); print(y); printf(" = "); print(z); printf("\n");
    minu();     print(x); printf(" - "); print(y); printf(" = "); print(z); printf("\n");
    multi();    print(x); printf(" * "); print(y); printf(" = "); print(z); printf("\n");
    divide();   print(x); printf(" / "); print(y); printf(" = "); 
    if(z.dentor == 0)     printf("Inf");
    else                  print(z); 
    return 0;
}
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
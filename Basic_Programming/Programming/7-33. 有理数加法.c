#include <stdio.h>

int gcd(int p, int q)
{
    if(q == 0) return p;
    else       return gcd(q, p % q);   // 递归求得分子分母最大公因数
}

int main()
{
    int a, b, c, d;
    scanf("%d/%d %d/%d", &a, &b, &c, &d); 
    a = a * d + c * b;          // 将相加后结果储存到a，b中
    b = b * d;
    if(a % b == 0)         printf("%d\n", a / gcd(a, b));   // 约分后分母为 1
    else printf("%d/%d\n", a / gcd(a, b), b / gcd(a, b));
    return 0;
}
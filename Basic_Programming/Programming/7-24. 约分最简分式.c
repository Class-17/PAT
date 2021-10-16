#include <stdio.h>

int gcd(int p, int q)    // 递归地利用辗转相除法，求得两数的最大公约数
{
    if(q == 0) return p;
    else       return gcd(q, p % q);
}

int main()
{
    int a, b;
    scanf("%d/%d", &a, &b);
    printf("%d/%d\n", a / gcd(a, b), b / gcd(a, b)); // 原分子分母同时除以最大公约数，输出
    return 0;
}
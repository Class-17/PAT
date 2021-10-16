#include <stdio.h>

int gcd(int p, int q)
{
    if(q == 0) return p;
    else       return gcd(q, p % q);   // 递归求得分子分母最大公因数
}

int main()
{
    int N, a, b, num = 0, den = 1;
    scanf("%d", &N);
    for(int i = 0; i < N; i++) {
        scanf("%d/%d", &a, &b);
        num = num * b  + a * den;   // 加上新输入的有理数
        den *= b;
        int temp = gcd(num, den);  // 随时化简，防止溢出
        num /= temp;
        den /= temp; 
    }
    den *= N;   //分母 * 有理数总数 得到平均数
    if(num < 0) {    // 发现结果为负数，输出符号，分子取绝对值 
        printf("-");
        num *= -1;
    }
    if(num % den == 0)         // 约分后分母为 1
        printf("%d\n", num / gcd(num, den));
    else 
        printf("%d/%d\n", num / gcd(num, den), den / gcd(num, den));
}
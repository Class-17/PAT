#include <stdio.h>
#include <math.h>

double a1, b1, a2, b2;                  // 全部变量，便于函数使用

void count(double a, char c, double b)
{
    if      (b1 >= 0 && b2 >= 0)   // 根据虚数部分正负，判断是否输出加号            
        printf("(%.1lf+%.1lfi) %c (%.1lf+%.1lfi) = ", a1, b1, c, a2, b2);
    else if (b1 >= 0 && b2 < 0)  
        printf("(%.1lf+%.1lfi) %c (%.1lf%.1lfi) = ", a1, b1, c, a2, b2);
    else if (b1 < 0 && b2 >= 0)
        printf("(%.1lf%.1lfi) %c (%.1lf+%.1lfi) = ", a1, b1, c, a2, b2);
    else 
        printf("(%.1lf%.1lfi) %c (%.1lf%.1lfi) = ", a1, b1, c, a2, b2);

    if (fabs(a)< 0.1 && fabs(b) < 0.1) { // 特判 ，运算结果为零
        printf("0.0\n"); return; 
    }
    if (fabs(a) >= 0.1)     // a 不为零， 输出a
        printf("%.1lf", a);
    if (fabs(b) >= 0.1) {
        if (fabs(a) >= 0.1 && b > 0.0) printf("+%.1lfi", b); // a不为零且b大于零输出带加号结果
        else                           printf("%.1lfi", b);
    }
    printf("\n");
}
int main()
{
    double a, b;
    scanf("%lf %lf %lf %lf", &a1, &b1, &a2, &b2);

    a = a1 + a2; b = b1 + b2;
    count(a, '+', b);

    a = a1 - a2; b = b1 - b2;
    count(a, '-', b);

    a = a1 * a2 - b1 * b2; b = a1 * b2 + a2 * b1;
    count(a, '*', b);

    a = (a1 * a2 + b1 * b2) / (a2 * a2 + b2 * b2);
    b = (a2 * b1 - a1 * b2) / (a2 * a2 + b2 * b2);
    count(a, '/', b);

    return 0;
}
/*
本题需特别注意输出格式；
虚数部分前需不需要 '+'， 根据输入负数的虚数部分的正负情况
判断为零：本题中运算结果绝对值小于 0.1，即为 0
*/
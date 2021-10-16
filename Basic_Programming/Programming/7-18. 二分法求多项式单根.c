#include <stdio.h>
#include <math.h>
#define EPS 1e-8        // 1e-8 为 10的-8次方，在此题中代替 0判断根

double a3, a2, a1, a0;  // 将系数设为全局变量，便于函数使用

double f(double x) {
    return a3 * pow(x, 3) + a2 * pow(x, 2) + a1 * x + a0;  // 求解方程 
}

int main()
{
    double a, b, root;
    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
    scanf("%lf %lf", &a, &b);
    if(f(a) == 0 || f(b) == 0) { // 特判边界为根，直接输出，程序结束
        printf("%.2lf", f(a) == 0 ? a : b); 
        return 0;
    }
    do {
        root = (a + b)/ 2;
        if(f(root) * f(a) < 0)      b = root;
        else                        a = root;
    } while(fabs(f(root)) > EPS);  // 在解特别接近 0的时候，判定根正确
    printf("%.2lf\n", root);
    return 0;
}
#include <stdio.h>
int main()
{
    int x; 
    double y;
    scanf("%d", &x);
    if(x <= 15) y = 4 * x / 3.0;   // 注意 写成 3.0
    else        y = 2.5 * x - 17.5;
    printf("%.2lf\n", y);   // 输出控制两位小数的格式
    return 0;
}
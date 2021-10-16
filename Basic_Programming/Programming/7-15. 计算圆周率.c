#include <stdio.h>
int main()
{
    double sum = 1, threshold;
    scanf("%lf", &threshold);
    for(double i = 1, temp = 1; temp > threshold; i++) // temp值大于阈值，退出循环
    {   // 注意使用 double 来储存 temp 和 i 
        temp = temp * i/ (2 * i + 1);  // 用 temp 储存当前项的值
        sum += temp;
    }
    printf("%.6lf\n", sum * 2); // 不要忘记*2
    return 0;
}
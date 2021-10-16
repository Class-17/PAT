#include <stdio.h>
int main()
{
    int age, time;
    double salary, sum;     // 用 salary 储存该员工的工资水平，sum储存工资
    scanf("%d %d", &age, &time);
    if(age < 5) salary = 30;
    else        salary = 50;
    if(time > 40) sum = (time - 40) * salary * 1.5 + 40 * salary;
    else          sum = time * salary;
    printf("%.2lf\n", sum);
    return 0;
}
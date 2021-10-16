#include <stdio.h>
#define MAXN 100
int main()
{
    int num, count = 0;
    scanf("%d", &num);
    for(int x = 1; x < 100; x++)        // 依次枚举 x 
        for(int y = x; y <= 100; y++)   // 依次从当前x的值出发，枚举 y
            if(x * x + y * y == num) {  // 满足条件，输出，计数器++
                printf("%d %d\n", x, y);
                count++;
            }
    if(count == 0)  // 计数器为零，表示没有解输出，特判无解
        printf("No Solution\n");
    return 0;
}
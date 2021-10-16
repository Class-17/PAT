#include <stdio.h>
int main()
{
    int A, count = 0;
    scanf("%d", &A);
    for(int a = A; a < A + 4; a++)   // 从A开始，依次举出一个数
        for(int b = A; b < A + 4; b++)
            for(int c = A; c < A + 4; c++)
                if(a != b && a != c && b != c)  // 循环到最后只要得到的三位数各不相等便输出
                {
                    printf("%d%d%d", a, b, c);
                    count++;         // count 计数控制输出
                    if(count % 6 == 0) printf("\n");
                    else               printf(" ");
                }
    return 0;       
}
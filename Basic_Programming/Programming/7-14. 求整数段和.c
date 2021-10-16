#include <stdio.h>
int main()
{
    int A, B, X = 0;
    scanf("%d %d", &A, &B);
    for(int i = 0; i < B - A + 1; i++) { // 以 B与 A的差 +1 为循环次数
        if(i % 5 == 0 && i != 0) printf("\n");  // 控制换行
        printf("%5d", A + i);      
        X += A + i;           // 计算总和
    }
    printf("\nSum = %d\n", X); // 注意换行
    return 0;
}
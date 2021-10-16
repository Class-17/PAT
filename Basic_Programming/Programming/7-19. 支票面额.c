#include <stdio.h>
#define MAXN 100
int main()
{
    int n;
    scanf("%d", &n);
    for(int f = 0; f < MAXN; f++)
        for(int y = 0; y < MAXN; y++)
            if(f * 98 - y * 199 == n) {  // 由推导出的公式判断是否为正解
                printf("%d.%d\n", y, f); // 得解，输出y.f，直接退出程序
                return 0;
            }
    printf("No Solution\n"); // 程序没有退出，说明没有找到解
    return 0;
}
/*
本题要点：
根据题意可得 y，f 与 n 的关系：
f * 100 + y - n = y * 200 + f * 2
f * 98 - y * 199 = n
题目中提到 n小于100，于是推测 y和 f也不超过100，设置循环依次枚举求解
*/
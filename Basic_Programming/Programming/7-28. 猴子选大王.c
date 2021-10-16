#include <stdio.h>
#define MAXN 1000
int main()
{
    int N, i, count = 0, monkey[MAXN] = {0};  // monkey数组用来储存猴子的状态，0代表在圈子内，1代表退出
    scanf("%d", &N);
    int num = N;
    while(num > 1) {         // num 储存当前圈子中还剩多少猴子，剩余一个猴子退出循环
        if(monkey[i] == 0)   // 当前猴子 状态为 0 可报数
            count++;        // count 用于记录当前猴子报数的数字
        if(count == 3) {      // 报数数字为三，该猴退出圈子 
            monkey[i] = 1;      // 猴子状态改为 1表示退出圈子
            num--;              // 圈子中猴子总数 -1
            count = 0;          // 报数器 满三清零
        }
        i++;                    // i++ 准备处理下一只猴子
        if(i == N) i = 0;       // 如果 i=N，应该从第一只猴子开始，反复循环
    }
    for(i = 0; i < N; i++)          // 制造循环，状态依然为 0的猴子为猴王 
        if(monkey[i] == 0)
            printf("%d\n", i + 1);   // 注意 +1
    return 0;
}
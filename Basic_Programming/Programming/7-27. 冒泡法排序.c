#include <stdio.h>
#define MAXN 100
int main()
{
    int N, K, num[MAXN];
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%d", &num[i]);
    for(int i = 0; i < K; i++)      // K为需要进行扫描的次数
        for(int j = 1; j < N - i; j++) // N-i 表示剩余的元素
            if(num[j - 1] > num[j]) {    // 如果后者小于前者，交换两个元素值
                int temp = num[j - 1];
                num[j - 1] = num[j];
                num[j] = temp;
            }
    for(int i = 0; i < N; i++)
        printf("%d%c", num[i], i < N - 1 ? ' ' : '\n');
    return 0;
}
/*
冒泡排序：
冒泡排序的本质是：交换，每次通过交换的方式，把当前剩余元素的最大值，
移动到另一端，而当剩余元素为 0 时，排序结束。
本题不要求完全排序整个数组，只需要完成K遍扫描，也就是说找出前 K个最大值，
依次放在数组的最右端即可（从右到左，由大到小）
*/
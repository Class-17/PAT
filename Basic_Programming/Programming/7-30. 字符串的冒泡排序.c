#include <stdio.h>
#include <string.h>
#define MAXN 100
int main()
{
    char s[MAXN][11];
    int N, K;
    scanf("%d %d", &N, &K);
    for(int i = 0; i < N; i++)
        scanf("%s", s[i]);
    for(int i = 0; i < K; i++)       // K为需要进行扫描的次数
        for(int j = 1; j < N - i; j++)  // N-i 表示剩余的元素
            if(strcmp(s[j - 1], s[j]) > 0) {    // 如果后者小于前者，交换两个元素值
                char temp[11];
                strcpy(temp, s[j - 1]);
                strcpy(s[j - 1], s[j]);
                strcpy(s[j], temp);
            }
    for(int i = 0; i < N; i++)
        printf("%s\n", s[i]);
    return 0;
}
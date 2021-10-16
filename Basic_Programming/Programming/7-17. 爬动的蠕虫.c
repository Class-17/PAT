#include <stdio.h>
int main()
{
    int N, U, D, time = 0, record = 0;
    scanf("%d %d %d", &N, &U, &D);
    while (record < N) { // record 记录当前位置，达到N（井口）退出循环
        if(time % 2 == 0) record += U;  // time 判断休息还是爬行
        else              record -= D;
        time++;    // 时间 +1
    }
    printf("%d", time);
    return 0;
}
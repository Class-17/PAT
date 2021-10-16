#include <stdio.h>
int main()
{
    int time, rabbit = 0, turtle = 0, i = 0;
    scanf("%d", &time);
    while(i < time) {
        rabbit += 9;
        turtle += 3;
        i++;                // 龟兔跑完后，时间+1
        if(i % 10 == 0 &&rabbit > turtle)   // 判断是否跑过10分钟，兔子是否超过乌龟
            for(int j = 0; j < 30 && i < time; j++, i++) // 内置循环，乌龟跑，兔子睡觉
                turtle += 3;
    }
    if(rabbit > turtle) 
        printf("^_^ %d\n", rabbit);
    else if(rabbit < turtle) 
        printf("@_@ %d\n", turtle);
    else
        printf("-_- %d\n", rabbit);
    return 0;
}
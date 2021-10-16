#include <stdio.h>
int main()
{
    double Open, Close, High, Low;
    scanf("%lf %lf %lf %lf", &Open, &High, &Low, &Close);
    if(Close < Open)      printf("BW-Solid");
    else if(Close > Open) printf("R-Hollow");
    else                  printf("R-Cross");  
    // 注意各个情况的逻辑关系
    if(High > Open && High > Close) {    
        if(Low < Open && Low < Close)
            printf(" with Lower Shadow and Upper Shadow\n");
        else 
            printf(" with Upper Shadow\n");
    }
    else if (Low < Open && Low < Close)
            printf(" with Lower Shadow\n");
    return 0;
}
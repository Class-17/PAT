#include<cstdio>
int main()
{
    double coef, record[1001] = {0};
    int num, exp, count = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d %lf", &exp, &coef);
        record[exp] += coef;
    }
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d %lf", &exp, &coef);
        record[exp] += coef;
    }
    for(int i = 0; i < 1001; i++)
        if(record[i] != 0) count++;
    printf("%d", count);
    for(int i = 1000; i >= 0; i--)
        if(record[i] != 0)
            printf(" %d %.1lf", i, record[i]);
    return 0;
}
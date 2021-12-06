#include<cstdio>
int main()
{
    int coef, exp, record[1001] = {0}, count = 0;
    while(scanf("%d %d", &coef, &exp) != EOF)
    {
        if(exp == 0) 
        {
            record[exp] += 0;
            continue;
        }
        coef *= exp;
        exp = exp - 1;
        record[exp] += coef;
    }
    for(int i = 1000; i >= 0; i--)
    {
        if(record[i] != 0)
            if(count == 0)
            {
                printf("%d %d", record[i], i);
                count++;
            }
            else
            {
                printf(" %d %d", record[i], i);
                count++;
            }                
    }
    if(count == 0) printf("0 0\n");
    else           printf("\n");
    return 0;
}
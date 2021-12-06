#include<cstdio>
int main()
{
    int num, count = 0;
    scanf("%d", &num);
    while(num != 1)
    {
        if(num % 2 == 0) num = num / 2;
        else             num = (3 * num + 1) / 2;
        count++;
    }
    printf("%d\n", count);
    return 0;
}
#include<cstdio>
int main()
{
    int num;
    scanf("%d", &num);
    for(int i = 0; i < num / 100; i++)
        printf("B");
    for(int i = 0; i < num % 100 / 10; i++)
        printf("S");
    for(int i = ; i <= num % 10; i++)
        printf("%d", i);
    return 0;
}
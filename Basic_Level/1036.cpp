#include<cstdio>
int main()
{
    int num;
    char c;
    scanf("%d %c", &num, &c);
    for(int i = 0; i < num; i++)
        printf("%c", c);
    printf("\n");
    for(int i = 0; i < (num + 1) / 2 - 2; i++)
    {
        for(int i = 0; i < num; i++)
            if(i > 0 && i < num -1) printf(" ");
            else                   printf("%c", c);
        printf("\n");
    }
    for(int i = 0; i < num; i++)
        printf("%c", c);
    printf("\n");
    return 0;
}
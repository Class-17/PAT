#include<cstdio>
#include<cstring>
int main()
{
    char str[82][82];
    int i = 0;
    while (scanf("%s", str[i++]) != EOF);
    for(i = i - 2; i >0; i--)
        printf("%s ", str[i]);
    printf("%s\n", str[0]);
    return 0;
}
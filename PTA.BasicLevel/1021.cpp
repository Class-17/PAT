#include<cstdio>
int main()
{
    int count[10] = {0}, i = 0;
    char record[1001];
    while (scanf("%c", &record[i++]) != EOF);
    for(i = i - 2; i >= 0; i--)
        count[record[i] - '0']++;
    for(i = 0; i < 10; i++)
        if(count[i] != 0)
            printf("%d:%d\n", i, count[i]);
    return 0;
}
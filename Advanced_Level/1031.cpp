#include<cstdio>
int main()
{
    char c[82];
    int num = -1;
    do {
        num++;
        scanf("%c", &c[num]);
    } while (c[num] != '\n');
    int colum = (num + 2) / 3;
    int bottom = colum + (num + 2) % 3;
    for(int i = 0; i < colum - 1; i++) {
        printf("%c", c[i]);
        for(int j = 0; j < bottom - 2; j++)
            printf(" ");
        printf("%c\n", c[num - i - 1]);
    }
    for(int i = colum - 1; i < colum + bottom - 1; i++)
        printf("%c", c[i]);
    return 0;
}
#include <stdio.h>
int main()
{
    int num;
    scanf("%d", &num);
    num = num / 16  * 10 + num % 16;
    printf("%d\n", num);
    return 0;
}
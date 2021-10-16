#include <stdio.h>
int main()
{
    int hours, minutes;
    scanf("%d:%d", &hours, &minutes);
    if(hours < 12)
        printf("%d:%d AM\n", hours, minutes);
    else if(hours == 12)
        printf("%d:%d PM\n", hours, minutes);
    else
        printf("%d:%d PM\n", hours - 12, minutes);
    return 0;
}
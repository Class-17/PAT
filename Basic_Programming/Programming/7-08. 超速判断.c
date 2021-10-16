#include <stdio.h>
int main()
{
    int speed;
    scanf("%d", &speed);
    if(speed <= 60)
        printf("Speed: %d - OK\n", speed);
    else
        printf("Speed: %d - Speeding\n", speed);
    return 0;
}
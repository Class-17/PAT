#include<cstdio>
int main()
{
    int A, Al, Asum = 0, B, Bl, Bsum = 0, num;
    scanf("%d", &num);
    while(num--)
    {
        scanf("%d %d %d %d", &A, &Al, &B, &Bl);
        if(A + B == Al && A + B != Bl)  Bsum++;
        if(A + B != Al && A + B == Bl)  Asum++;
    }
    printf("%d %d\n", Asum, Bsum);
    return 0;
}
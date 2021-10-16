#include<cstdio>
int main()
{
    int N;
    scanf("%d", &N);
    long double temp, sum = 0.0;
    for(int i = 0; i < N; i++)
    {
        scanf("%Lf", &temp);
        sum += temp * (i + 1) * (N - i);
    }
    printf("%.2Lf\n", sum);
    return 0;
}
#include<cstdio>
int main()
{
    int N, K, temp, grades[101] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &temp);
        grades[temp]++;
    }
    scanf("%d", &K);
    for(int i = 0; i < K; i++)
    {
        scanf("%d", &temp);
        printf("%d", grades[temp]);
        if(i != K - 1) printf(" ");
        else           printf("\n");
    }
    return 0;
}
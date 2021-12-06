#include<cstdio>

const int MOD = 1000000007;

int main()
{
    int P = 0, PA = 0, PAT = 0;
    char temp;
    while ((temp = getchar()) != '\n')
    {
        if(temp == 'P') P = P + 1;
        if(temp == 'A') PA = (PA + P) % MOD;
        if(temp == 'T') PAT = (PAT + PA) % MOD;
    }
    printf("%d\n", PAT);
    return 0;
}
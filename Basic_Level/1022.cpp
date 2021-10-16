#include<cstdio>
int main()
{
    int A, B, D, i = 0, record[50] = {0};
    scanf("%d %d %d", &A, &B, &D);
    A += B;
    do
    {
        record[i++] += A % D;
        A /= D;
    }while(A > 0);
    for(i -= 1; i >= 0; i--) 
        printf("%d", record[i]);
    printf("\n");
    return 0;    
}

#include<cstdio>
#include<cmath>
int main()
{
    int num, temp;
    scanf("%d", &num);
    int A[5] = {0}, count[5] = {0};
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &temp);
        if(temp % 2 == 0 && temp % 5 == 0) {A[0] += temp; count[0]++;}
        if(temp % 5 == 1) {A[1] += pow(-1, count[1]) * temp; count[1]++;}
        if(temp % 5 == 2) {A[2]++; count[2]++;}
        if(temp % 5 == 3) {A[3] += temp; count[3]++;}; 
        if(temp % 5 == 4 && temp > A[4]) {A[4] = temp; count[4]++;}
    }
    for(int i = 0; i < 5; i++)
    {
        if(count[i] == 0) printf("N");
        else if(i == 3)   printf("%.1lf", (double)A[3] / count[3]);
        else              printf("%d", A[i]);
        printf("%c", i < 4 ? ' ' : '\n');
    }
    return 0;
}
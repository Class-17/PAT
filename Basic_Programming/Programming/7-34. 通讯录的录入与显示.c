#include <stdio.h>
#define MAXN 10

struct Info {
    char name[20];
    char birthday[20];
    char sex;
    char fixNum[20];
    char num[20];
} frd[MAXN];

int main()
{
    int N, K;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
        scanf("%s %s %c %s %s", frd[i].name, frd[i].birthday, &frd[i].sex, frd[i].fixNum, frd[i].num);
    scanf("%d", &K);
    while (K--) {
        int temp;
        scanf("%d", &temp);
        if(temp < N && temp >= 0)
             printf("%s %s %s %c %s\n", frd[temp].name, frd[temp].fixNum, frd[temp].num, frd[temp].sex, frd[temp].birthday);
        else printf("Not Found\n");   
    }
    return 0;
}
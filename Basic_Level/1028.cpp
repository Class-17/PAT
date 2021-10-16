#include<cstdio>
struct Info
{
    char name[15];
    int year, month, day;
}temp, oldest, youngest;
int main()
{
    int N, count = 0;
    scanf("%d", &N);
    oldest.year = 2014; oldest.month = 9; oldest.day = 7;
    youngest.year = 1814; youngest.month = 9; youngest.day = 5;
    for(int i = 0; i < N; i++)
    {
        scanf("%s %d/%d/%d",temp.name, &temp.year, &temp.month, &temp.day);
        int judge = temp.year * 10000 + temp.month * 100 + temp.day;
        if(judge >= 18140906 && judge <= 20140906)
        {
            int youngestjudge = youngest.year * 10000 + youngest.month * 100 + youngest.day;
            int oldestjudge = oldest.year * 10000 + oldest.month * 100 + oldest.day;
            if(judge > youngestjudge) youngest = temp;
            if(judge < oldestjudge)   oldest =temp;
            count++;
        }
    }
    if(count == 0) printf("0");
    else           printf("%d %s %s\n", count, oldest.name, youngest.name);
    return 0;
}
#include<cstdio>
#include<algorithm>
using namespace std;
struct Info
{
    int ID; 
    int virGrade, talGrade;
    int flag;
}per[100000];

bool cmp(Info a, Info b)
{
    if(a.flag != b.flag)    return a.flag < b.flag;
    else if(a.virGrade + a.talGrade != b.virGrade + b.talGrade)
                return a.virGrade + a.talGrade > b.virGrade + b.talGrade;
    else if(a.virGrade != b.virGrade)   
                return a.virGrade > b.virGrade;
    else        return a.ID < b.ID;         
}

int main()
{
    int num, count = 0, L, H;
    scanf("%d %d %d", &num, &L, &H);
    for(int i = 0; i < num; i++)
    {
        scanf("%d %d %d", &per[count].ID, &per[count].virGrade, &per[count].talGrade);
        if(per[count].virGrade >= L && per[count].talGrade >= L)  
        {
            if(per[count].virGrade >= H && per[count].talGrade >= H)
                    per[count].flag = 1;
            else if(per[count].virGrade >= H)
                    per[count].flag = 2;
            else if(per[count].virGrade >= per[count].talGrade)
                    per[count].flag = 3;
            else    per[count].flag = 4;
            count++;
        }
    }
    printf("%d\n", count);
    sort(per, per + count, cmp);
    for(int i = 0; i < count; i++)
        printf("%08d %d %d\n", per[i].ID, per[i].virGrade, per[i].talGrade);
    return 0;
}
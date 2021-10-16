#include<cstdio>
#include<algorithm>
using namespace std;

struct Info
{
    long long ID;
    int score;
    int locNum;
    int locRank;
}stu[30000];

bool cmp(Info a, Info b)
{
    if(a.score != b.score) return a.score > b.score;
    else                   return a.ID < b.ID;    
}

int main()
{
    int num, K, count = 0;
    scanf("%d", &num);
    for(int i = 0; i < num; i++)
    {
        scanf("%d", &K);
        for(int j = 0; j < K; j++)
        {
            scanf("%lld %d", &stu[count].ID, &stu[count].score);
            stu[count++].locNum = i + 1;
        }
        sort(stu + count - K, stu + count, cmp);
        stu[count - K].locRank = 1;
        for(int j = count - K + 1; j < count; j++)
            if(stu[j].score == stu[j - 1].score) {stu[j].locRank = stu[j - 1].locRank;}
            else                                 {stu[j].locRank = j + 1 - (count - K);}
    }
    sort(stu, stu + count, cmp);
    printf("%d\n", count);
    for(int i = 0, rank = 1; i < count; i++)
    {
        if(i != 0 && stu[i].score < stu[i - 1].score) rank = i + 1;
        printf("%013lld %d %d %d\n", stu[i].ID, rank, stu[i].locNum, stu[i].locRank);
    }
    return 0;
}
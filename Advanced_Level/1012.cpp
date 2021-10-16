#include<cstdio>
#include<algorithm>
using namespace std;
struct Info
{
    int ID;
    int grads[4];
    int rank[4];
}stu[2000];

int now;

bool cmp(Info a, Info b)
{
    if(a.grads[now] != b.grads[now])
            return a.grads[now] > b.grads[now];
    else    return a.ID < b.ID;
}

int main()
{
    int N, M;
    char courses[4] = {'A', 'C', 'M', 'E'};
    scanf("%d %d", &N, &M);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &stu[i].ID);
        for(int j = 1; j < 4; j++)
            scanf("%d", &stu[i].grads[j]);
        stu[i].grads[0] = (stu[i].grads[1] + stu[i].grads[2] + stu[i].grads[3]) / 3;
    }
    for(now = 0; now < 4; now++)
    {
        sort(stu, stu + N, cmp);
        stu[0].rank[now] = 1;
        for(int j = 1; j < N; j++)
        {
            if(stu[j].grads[now] == stu[j - 1].grads[now])
                    stu[j].rank[now] = stu[j - 1].rank[now];
            else    stu[j].rank[now] = j + 1;
        }
    }
    for(int i = 0; i < M; i++)
    {
        int temp;
        scanf("%d", &temp);
        for(int j = 0; j < N; j++)
            if(stu[j].ID == temp)
            {
                int high = 0;
                for(int t = 1; t < 4; t++)
                    if(stu[j].rank[t] < stu[j].rank[high])
                        high = t;
                printf("%d %c\n", stu[j].rank[high], courses[high]);
                break;
            }
            else if(j == N - 1) printf("N/A\n");
    }
    return 0;
}
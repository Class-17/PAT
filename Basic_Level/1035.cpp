#include<cstdio>
#include<algorithm>
using namespace std;

const int MAXN = 100;

int N, self[2][MAXN], record[MAXN];

bool compare(int obj[])
{
    for(int i = 0; i < N; i++)
        if(obj[i] != record[i])  return false;
    return true;
}

bool InsertSort()
{
    bool isRight = false;
    for(int i = 1; i < N; i++)
    {
        int temp = self[0][i], now = i;
        while(now > 0 && temp < self[0][now - 1])
        {
            self[0][now] = self[0][now - 1];
            self[0][--now] = temp;
        }
        if(isRight) break;
        isRight = compare(self[0]);
    }  
    return isRight;  
}

bool MergeSort()
{
    bool isRight = false;
    for(int step = 2; step / 2 < N; step *= 2)
    {
        for(int i = 0; i < N; i += step)
            sort(self[1] + i, self[1] + min(i + step, N));
        if(isRight) break;
        isRight = compare(self[1]);
    }
    return isRight;
}

void input()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {   
        scanf("%d", &self[0][i]);
        self[1][i] = self[0][i];
    }    
    for (int i = 0; i < N; i++)
        scanf("%d", &record[i]);
}

void output(int num)
{
    for(int i = 0; i < N - 1; i++)
        printf("%d ", self[num][i]);
    printf("%d\n", self[num][N - 1]); 
}

int main()
{
    input();
    if(InsertSort())     
        {printf("Insertion Sort\n"); output(0);}
    else if(MergeSort()) 
        {printf("Merge Sort\n"); output(1);}      
    return 0;
}
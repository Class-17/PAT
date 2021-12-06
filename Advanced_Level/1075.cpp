#include <stdio.h>
#include <stdbool.h>

#define MAXN 10000
#define MAXP 5
#define NOTSUBMIT -10 

struct Info {
    int ID;
    int Grades[MAXP];
    int TotalScore;
    int ACNum;
};

typedef struct Info ElementType; 

int cmp(const ElementType * a, const ElementType * b)
{
    if(a->TotalScore ==  b->TotalScore)
        if(a->ACNum == b->ACNum) return b->ID - a->ID;
        else                     return a->ACNum - b->ACNum;
    return a->TotalScore - b->TotalScore;
}

void ShellSort(ElementType * Array, int N)
{
    int h = 1;
    while (h < N / 3) h = h * 3 + 1;
    while (h >= 1) {
        for(int i = h; i < N; i++) {
            ElementType X = Array[i];
            int j = i;
            while (j >= h && cmp(&X, &Array[j - h]) > 0) {
                Array[j] = Array[j - h];
                j -= h;
            }
            Array[j] = X;   
        }
        h /= 3;
    }
}

bool IsSubmit(ElementType A, int K)
{
    for(int i = 0; i < K; i++)
        if(A.Grades[i] != NOTSUBMIT) return true;
    return false;
}

int main()
{
    int N, K, M;
    scanf("%d %d %d", &N, &K, &M);
    struct Info stu[MAXN];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++)
            stu[i].Grades[j] = NOTSUBMIT;
        stu[i].ID = i + 1;
        stu[i].TotalScore = 0;
        stu[i].ACNum = 0;
    }
    int p[MAXP];
    for(int i = 0; i < K; i++)
        scanf("%d", &p[i]);
    for(int i = 0; i < M; i++) {
        int ID, PNum, Score;
        scanf("%d %d %d", &ID, &PNum, &Score);
        if(Score == -1) Score = 0;
        if(Score > stu[ID - 1].Grades[PNum - 1]) {
            if(stu[ID - 1].Grades[PNum - 1] != NOTSUBMIT)
                stu[ID - 1].TotalScore += Score - stu[ID - 1].Grades[PNum - 1];
            else   
                stu[ID - 1].TotalScore += Score;
            stu[ID - 1].Grades[PNum - 1] = Score;
            if(Score == p[PNum - 1]) stu[ID - 1].ACNum++;
        }
    }
    ShellSort(stu, N);
    for(int i = 0, rank = 1; i < N && IsSubmit(stu[i], K); i++) {
        if(i > 0 && stu[i - 1].TotalScore > stu[i].TotalScore)
            rank = i + 1;
        printf("%d %05d %d", rank, stu[i].ID, stu[i].TotalScore);
        for(int j = 0; j < K; j++)
            if(stu[i].Grades[j] != NOTSUBMIT) 
                printf(" %d", stu[i].Grades[j]);
            else  
                printf(" -");
        printf("\n");
    }  
    return 0;
}
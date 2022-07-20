#include<cstdio>
int main()
{
    int hashTable[1001] = {0};
    int N, highest = 0;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        int temp, code, grades;
        scanf("%d-%d %d", &temp, &code, &grades);
        hashTable[temp] += grades;
        if(hashTable[temp] > hashTable[highest])
            highest = temp;
    }
    printf("%d %d\n", highest, hashTable[highest]);
    return 0;
}
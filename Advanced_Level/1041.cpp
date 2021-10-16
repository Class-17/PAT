#include<cstdio>
int main()
{
    int hashTable[10001] = {0}, record[100001];
    int N;
    scanf("%d", &N);
    for(int i = 0; i < N; i++)
    {
        scanf("%d", &record[i]);
        hashTable[record[i]]++;
    }
    for(int i = 0; i < N; i++)
        if(hashTable[record[i]] == 1) 
        {
            printf("%d\n", record[i]);
            break;
        }
        else if(i == N - 1)   
            printf("None\n");
    return 0;
}
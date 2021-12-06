#include<cstdio>
#include<algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    bool hashTable[10000] = {false};
    int K, record[100];
    scanf("%d", &K);
    for(int i = 0; i < K; i++)
    {
        scanf("%d", &record[i]);
        int temp = record[i];
        while (temp !=  1)
        {
            if(temp % 2 == 0) temp /= 2;
            else              temp = (temp * 3 + 1) / 2;
            hashTable[temp] = true;
        }
    }
    sort(record, record + K, cmp);
    for(int i = 0, count = 0; i < K; i++)
        if(hashTable[record[i]] == false)
        {
            if(count != 0) printf(" ");
            printf("%d", record[i]);
            count++;
        }
    return 0;
}